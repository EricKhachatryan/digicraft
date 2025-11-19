#include "common.h"
#include <thread>
#include <atomic>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    int port = (argc > 1) ? std::stoi(argv[1]) : DEFAULT_PORT;

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        return 1;
    }

    int opt = 1;
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(listen_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(listen_fd);
        return 1;
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        close(listen_fd);
        return 1;
    }

    std::cout << "Server listening on port " << port << "..." << std::endl;

    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);
    int client_fd = accept(listen_fd, (sockaddr*)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("accept");
        close(listen_fd);
        return 1;
    }

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
    std::cout << "Client connected: " << client_ip << ":" 
              << ntohs(client_addr.sin_port) << std::endl;

    std::atomic<bool> running(true);

    // thread: receive from client
    std::thread reader([&]() {
        char buf[BUF_SIZE];
        while (running) {
            ssize_t n = recv(client_fd, buf, BUF_SIZE - 1, 0);
            if (n <= 0) {
                if (n == 0) std::cout << "Peer disconnected.\n";
                else perror("recv");
                running = false;
                break;
            }
            buf[n] = '\0';
            std::cout << "Client: " << buf << std::flush;
        }
    });

    // main thread: send input to client
    std::string line;
    while (running && std::getline(std::cin, line)) {
        line += '\n';
        if (send(client_fd, line.c_str(), line.size(), 0) < 0) {
            perror("send");
            running = false;
            break;
        }
    }

    running = false;
    shutdown(client_fd, SHUT_RDWR);
    close(client_fd);
    close(listen_fd);
    if (reader.joinable()) reader.join();

    std::cout << "Server exiting." << std::endl;
    return 0;
}

