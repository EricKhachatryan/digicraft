#include "common.h"
#include <thread>
#include <atomic>


int main(int argc, char* argv[]) {
const char* server_ip = (argc > 1) ? argv[1] : "127.0.0.1";
int port = (argc > 2) ? std::stoi(argv[2]) : DEFAULT_PORT;


int sock = socket(AF_INET, SOCK_STREAM, 0);
if (sock < 0) {
perror("socket");
return 1;
}


sockaddr_in serv_addr{};
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(port);
if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
std::cerr << "Invalid address: " << server_ip << std::endl;
close(sock);
return 1;
}


if (connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
perror("connect");
close(sock);
return 1;
}


std::cout << "Connected to " << server_ip << ":" << port << std::endl;


std::atomic<bool> running(true);


// thread: receive from server and print
std::thread reader([&]() {
char buf[BUF_SIZE];
while (running) {
ssize_t n = recv(sock, buf, BUF_SIZE - 1, 0);
if (n <= 0) {
if (n == 0) std::cout << "Peer disconnected.\n";
else perror("recv");
running = false;
break;
}
buf[n] = '\0';
std::cout << "Server: " << buf << std::flush;
}
});


// main thread: read stdin and send
std::string line;
while (running && std::getline(std::cin, line)) {
line += '\n';
ssize_t sent = send(sock, line.c_str(), line.size(), 0);
if (sent < 0) {
perror("send");
running = false;
break;
}
}


running = false;
shutdown(sock, SHUT_RDWR);
close(sock);
if (reader.joinable()) reader.join();
std::cout << "Client exiting." << std::endl;
return 0;
}
