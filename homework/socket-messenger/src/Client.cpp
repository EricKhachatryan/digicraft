#include "../include/Client.hpp"
#include "../include/Message.hpp"
#include <iostream>
#include <unistd.h>

Client::Client() : config(Config::load()) {}

bool Client::connectToServer(const std::string& ip, int port) {
    std::string target_ip = ip.empty() ? config.client_default_ip : ip;
    int target_port = port == 0 ? config.client_default_port : port;

    std::cout << "Подключение к " << target_ip << ":" << target_port << "...\n";
    if (!conn.connect(target_ip, target_port)) {
        std::cerr << "Не удалось подключиться к серверу.\n";
        return false;
    }
    std::cout << "Подключено!\n";
    return true;
}

void Client::login() {
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, username);
    if (username.empty()) username = "Eric";

    Message auth(MessageType::AUTH_REQUEST, username);
    conn.send(auth);
}

void Client::receiveLoop() {
    while (running) {
        Message msg;
        if (!conn.receive(msg)) {
            if (running) std::cout << "\n[Сервер отключился]\n";
            break;
        }

        switch (msg.type) {
            case MessageType::TEXT:
                printWithPrefix(msg.sender + ": ", msg.content);
                break;
            case MessageType::AUTH_SUCCESS:
                std::cout << "Добро пожаловать, " << msg.content << "!\n";
                break;
            case MessageType::AUTH_FAILED:
                std::cout << "Ошибка входа: " << msg.content << "\n";
                running = false;
                break;
            default:
                break;
        }
    }
}

void Client::printWithPrefix(const std::string& prefix, const std::string& text) {
    std::cout << "\r" << std::string(50, ' ') << "\r";  // очистка строки ввода
    std::cout << prefix << text << std::flush;
    if (!text.empty() && text.back() != '\n') std::cout << "\n> ";
}

void Client::run() {
    login();
    running = true;
    recv_thread = std::thread(&Client::receiveLoop, this);

    std::string line;
    while (running && std::getline(std::cin, line)) {
        if (line == "/quit") break;
        if (!line.empty()) {
            Message msg(MessageType::TEXT, username, line);
            if (!conn.send(msg)) break;
        }
        std::cout << "> " << std::flush;
    }

    stop();
}

void Client::stop() {
    running = false;
    Message bye(MessageType::DISCONNECT, username);
    conn.send(bye);
    conn.close();
    if (recv_thread.joinable()) recv_thread.join();
}
