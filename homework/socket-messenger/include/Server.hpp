#pragma once
#include "Connection.hpp"
#include "Database.hpp"
#include "Config.hpp"
#include <vector>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <atomic>

struct ClientInfo {
    Connection conn;
    std::string username;
};

class Server {
    Config config;
    Connection listener;
    Database db;
    std::vector<ClientInfo> clients;
    std::mutex clients_mutex;
    std::atomic_bool running{true};

    void handleClient(ClientInfo client);
    void broadcast(const Message& msg, const Connection* exclude = nullptr);
    void removeClient(const Connection* conn);

public:
    Server();
    bool start();
    void run();
    void stop();
};
