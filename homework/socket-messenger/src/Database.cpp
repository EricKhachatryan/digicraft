// Database.cpp
#include "../include/Database.hpp"
#include <iostream>

bool Database::open(const std::string& path) {
    if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << "\n";
        return false;
    }
    const char* sql = "CREATE TABLE IF NOT EXISTS messages("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "sender TEXT, content TEXT, timestamp INTEGER);";
    char* err = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &err);
    if (err) { std::cerr << "SQL error: " << err << "\n"; sqlite3_free(err); }
    return true;
}

bool Database::saveMessage(const std::string& sender, const std::string& content) {
    std::string sql = "INSERT INTO messages(sender,content,timestamp) VALUES(?, ?, strftime('%s','now'));";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) return false;
    sqlite3_bind_text(stmt, 1, sender.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, content.c_str(), -1, SQLITE_STATIC);
    bool ok = sqlite3_step(stmt) == SQLITE_DONE;
    sqlite3_finalize(stmt);
    return ok;
}

void Database::close() {
    if (db) sqlite3_close(db);
    db = nullptr;
}
