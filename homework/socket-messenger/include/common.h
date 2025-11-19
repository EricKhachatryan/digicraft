#ifndef COMMON_H
#define COMMON_H


#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>


#include <cstring>
#include <iostream>
#include <string>


constexpr int DEFAULT_PORT = 12345;
constexpr int BACKLOG = 1;
constexpr int BUF_SIZE = 1024;


#endif // COMMON_H
