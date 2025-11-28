#include "../include/Config.hpp"
#include <fstream>
#include <iostream>

Config Config::load(const std::string& path) {
    Config cfg;
    std::ifstream f(path);
    if (!f.is_open()) {
        std::cerr << "Warning: Config not found, using defaults\n";
        return cfg;
    }
    json j;
    try { f >> j; }
    catch (...) { std::cerr << "Warning: Bad config, using defaults\n"; return cfg; }

    if (j.contains("server")) {
        auto& s = j["server"];
        cfg.server_port = s.value("port", 12345);
        cfg.server_host = s.value("host", "0.0.0.0");
        cfg.backlog = s.value("backlog", 10);
        cfg.db_path = s.value("database_path", "messenger.db");
    }
    if (j.contains("client")) {
        auto& c = j["client"];
        cfg.client_default_ip = c.value("default_server_ip", "127.0.0.1");
        cfg.client_default_port = c.value("default_port", 12345);
    }
    return cfg;
}
