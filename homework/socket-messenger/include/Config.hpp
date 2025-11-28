#pragma once
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

struct Config {
    // Server
    int server_port = 12345;
    std::string server_host = "0.0.0.0";
    int backlog = 10;
    std::string db_path = "messenger.db";

    // Client
    std::string client_default_ip = "127.0.0.1";
    int client_default_port = 12345;

    static Config load(const std::string& path = "config.json");
};
