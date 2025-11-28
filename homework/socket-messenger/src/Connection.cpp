#include "../include/Connection.hpp"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

bool Connection::createSocket() {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) { perror("socket"); return false; }
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    return true;
}

bool Connection::connect(const std::string& ip, int port) {
    if (!createSocket()) return false;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip.c_str(), &addr.sin_addr) <= 0) {
        std::cerr << "Invalid IP: " << ip << "\n";
        close(); return false;
    }
    if (::connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(); return false;
    }
    return true;
}

bool Connection::bindAndListen(const std::string& host, int port, int backlog) {
    if (!createSocket()) return false;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &addr.sin_addr);

    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); close(); return false;
    }
    if (listen(fd, backlog) < 0) {
        perror("listen"); close(); return false;
    }
    return true;
}

Connection Connection::acceptClient() const {
    struct sockaddr_in client_addr{};
    socklen_t len = sizeof(client_addr);
    int client_fd = accept(fd, (struct sockaddr*)&client_addr, &len);
    if (client_fd < 0) { perror("accept"); return Connection(-1); }
    return Connection(client_fd);
}

bool Connection::send(const Message& msg) const {
    if (!good()) return false;
    auto data = msg.serialize();
    return ::send(fd, data.data(), data.size(), 0) == (ssize_t)data.size();
}

bool Connection::receive(Message& msg) const {
    if (!good()) return false;
    char header[13];
    if (::recv(fd, header, 13, MSG_WAITALL) != 13) return false;

    uint16_t sender_len = ntohs(*reinterpret_cast<uint16_t*>(header + 3));
    uint16_t content_len = ntohs(*reinterpret_cast<uint16_t*>(header + 5));
    std::vector<char> rest(sender_len + content_len);
    if (::recv(fd, rest.data(), rest.size(), MSG_WAITALL) != (ssize_t)rest.size())
        return false;

    std::vector<char> full;
    full.insert(full.end(), header, header + 13);
    full.insert(full.end(), rest.begin(), rest.end());
    msg = Message::deserialize(full);
    return true;
}

void Connection::close() {
    if (fd >= 0) { shutdown(fd, SHUT_RDWR); ::close(fd); fd = -1; }
}

std::string Connection::peerIP() const {
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addr.sin_addr, ip, sizeof(ip));
    return ip;
}

int Connection::peerPort() const { return ntohs(addr.sin_port); }
