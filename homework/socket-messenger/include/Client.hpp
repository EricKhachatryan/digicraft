#pragma once
#include "Connection.hpp"
#include "Database.hpp"
#include "Config.hpp"
#include <thread>
#include <atomic>
#include <string>

class Client {
    Config config;
    Connection conn;
    std::string username;
    std::atomic_bool running{false};
    std::thread recv_thread;

    void receiveLoop();
    void printWithPrefix(const std::string& prefix, const std::string& text);

public:
    Client();
    bool connectToServer(const std::string& ip = "", int port = 0);
    void login();
    void run();
    void stop();
};
