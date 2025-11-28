#include "../include/Client.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    Client client;

    std::string ip;
    int port = 0;
    if (argc > 1) ip = argv[1];
    if (argc > 2) port = std::stoi(argv[2]);

    if (!client.connectToServer(ip, port)) return 1;

    std::cout << "=== Мессенджер ===\n";
    std::cout << "Введите /quit для выхода\n> " << std::flush;

    client.run();
    return 0;
}
