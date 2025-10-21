#include "../include/db_wrapper.h"
#include <iostream>

DBWrapper::DBWrapper(const std::string& filename) : db(nullptr) {
    if (sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database: " + std::string(sqlite3_errmsg(db)));
    }

    execute("PRAGMA foreign_keys = ON;");

    execute(R"(
        CREATE TABLE IF NOT EXISTS categories (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT UNIQUE
        );
        CREATE TABLE IF NOT EXISTS todos (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            category_id INTEGER,
            due_date TEXT,
            done INTEGER DEFAULT 0,
            FOREIGN KEY(category_id) REFERENCES categories(id)
        );
    )");
}

DBWrapper::~DBWrapper() {
    if (db) {
        sqlite3_close(db);
    }
}

void DBWrapper::execute(const std::string& sql) {
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string msg = errMsg ? errMsg : "Unknown SQL error";
        sqlite3_free(errMsg);
        throw std::runtime_error("SQLite error: " + msg);
    }
}

sqlite3_stmt* DBWrapper::prepare(const std::string& sql) {
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare statement: " + std::string(sqlite3_errmsg(db)));
    }
    return stmt;
}

void DBWrapper::beginTransaction() {
    execute("BEGIN TRANSACTION;");
}

void DBWrapper::commit() {
    execute("COMMIT;");
}

void DBWrapper::rollback() {
    execute("ROLLBACK;");
}

sqlite3* DBWrapper::raw() {
    return db;
}
