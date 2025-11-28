// Database.hpp
#pragma once
#include <string>
#include <sqlite3.h>

class Database {
    sqlite3* db = nullptr;
public:
    Database() = default;
    bool open(const std::string& path);
    void close();
    bool saveMessage(const std::string& sender, const std::string& content);
    ~Database() { close(); }
};
