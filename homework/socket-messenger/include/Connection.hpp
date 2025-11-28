#pragma once
#include "Message.hpp"
#include <arpa/inet.h>
#include <string>

class Connection {
protected:
    int fd = -1;
    struct sockaddr_in addr{};

public:
    explicit Connection(int f = -1) : fd(f) {}
    ~Connection() { close(); }

    bool createSocket();
    bool connect(const std::string& ip, int port);
    bool bindAndListen(const std::string& host, int port, int backlog = 10);
    Connection acceptClient() const;

    bool send(const Message& msg) const;
    bool receive(Message& msg) const;

    void close();
    bool good() const { return fd >= 0; }
    std::string peerIP() const;
    int peerPort() const;
    int getFd() const { return fd; }
};
