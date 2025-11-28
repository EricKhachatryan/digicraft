#include "../include/Server.hpp"
#include <csignal>
#include <iostream>

Server* server_ptr = nullptr;

void signal_handler(int) {
    if (server_ptr) server_ptr->stop();
}

int main() {
    std::signal(SIGINT, signal_handler);

    Server server;
    server_ptr = &server;

    if (!server.start()) return 1;

    server.run();
    std::cout << "Сервер остановлен.\n";
    return 0;
}
