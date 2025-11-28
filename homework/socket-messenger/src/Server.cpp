#include "../include/Server.hpp"
#include "../include/Message.hpp"
#include <iostream>
#include <algorithm>

Server::Server() : config(Config::load()) {
    db.open(config.db_path);
}

bool Server::start() {
    std::cout << "Запуск сервера на порту " << config.server_port << "...\n";
    return listener.bindAndListen(config.server_host, config.server_port, config.backlog);
}

void Server::handleClient(ClientInfo client_info) {  // ← принимаем по значению → сразу перемещаем
    // 1. Получаем сообщение авторизации
    Message auth_req;
    if (!client_info.conn.receive(auth_req) || 
        auth_req.type != MessageType::AUTH_REQUEST) 
    {
        client_info.conn.close();
        return;
    }

    // 2. Определяем имя
    std::string name = auth_req.sender;
    if (name.empty()) name = "Guest";

    // 3. Делаем имя уникальным и сразу ДОБАВЛЯЕМ клиента в список
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        bool name_taken = true;
        std::string original = name;
        int suffix = 1;
        while (name_taken) {
            name_taken = false;
            for (const auto& c : clients) {
                if (c.username == name) {
                    name = original + "_" + std::to_string(suffix++);
                    name_taken = true;
                    break;
                }
            }
        }
        client_info.username = name;
        clients.push_back(std::move(client_info));   // ← теперь можно, всё готово
    }

    // 4. Отправляем приветствие и оповещаем всех
    {
        Message welcome(MessageType::AUTH_SUCCESS, "Server", "Вы вошли как " + name);
        clients.back().conn.send(welcome);

        broadcast(Message(MessageType::TEXT, "Server", name + " присоединился к чату"));
    }

    // 5. Основной цикл чтения сообщений
    Message msg;
    while (running) {
        if (!clients.back().conn.receive(msg)) {
            break;   // ошибка или отключение
        }
        if (msg.type == MessageType::DISCONNECT) break;
        if (msg.type == MessageType::TEXT && !msg.content.empty()) {
            msg.sender = name;
            db.saveMessage(name, msg.content);
            broadcast(msg, &clients.back().conn);
        }
    }

    // 6. Выход
    broadcast(Message(MessageType::TEXT, "Server", name + " вышел из чата"));

    // Удаляем клиента из списка
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        auto it = std::find_if(clients.begin(), clients.end(),
            [&](const ClientInfo& ci) { return ci.username == name; });
        if (it != clients.end()) {
            it->conn.close();
            clients.erase(it);
        }
    }
}

void Server::broadcast(const Message& msg, const Connection* exclude) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    auto data = msg.serialize();
    for (auto& c : clients) {
        if (&c.conn == exclude) continue;
        ::send(c.conn.getFd(), data.data(), data.size(), 0);
    }
}

void Server::removeClient(const Connection* conn) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    clients.erase(std::remove_if(clients.begin(), clients.end(),
        [conn](const ClientInfo& ci) { return ci.conn.getFd() == conn->getFd(); }),
        clients.end());
}

void Server::run() {
    std::cout << "Сервер запущен! Ожидание подключений...\n";
    while (running) {
        Connection new_client = listener.acceptClient();
        if (!new_client.good()) {
            continue;
        }

        ClientInfo client_info;
        client_info.conn = std::move(new_client);

        // Запускаем обработчик в отдельном потоке и сразу отсоединяем
        std::thread(&Server::handleClient, this, std::move(client_info)).detach();
    }
}

void Server::stop() {
    running = false;
    listener.close();
}
