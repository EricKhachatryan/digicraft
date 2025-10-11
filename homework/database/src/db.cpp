#include "../include/db.h"
#include <iostream>

std::unique_ptr<DB> DB::instance = nullptr;

int DB::callback(void* /*unused*/, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; ++i) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    std::cout << "\n";
    return 0;
}

DB& DB::getInstance() {
    if (!instance)
        instance.reset(new DB());
    return *instance;
}

bool DB::open(const std::string& filename) {
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        db = nullptr;
        return false;
    }
    std::cout << "Database opened successfully.\n";
    return true;
}

bool DB::createTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS person("
                      "id INTEGER PRIMARY KEY, "
                      "name TEXT, "
                      "age INTEGER);";
    char* errmsg = nullptr;
    int rc = sqlite3_exec(db, sql, callback, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errmsg << "\n";
        sqlite3_free(errmsg);
        return false;
    }
    std::cout << "Table created successfully.\n";
    return true;
}

bool DB::insert(const std::string& name, int age) {
    std::string sql = "INSERT INTO person (name, age) VALUES ('" + name + "', " + std::to_string(age) + ");";
    char* errmsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errmsg << "\n";
        sqlite3_free(errmsg);
        return false;
    }
    std::cout << "Inserted: " << name << " (" << age << ")\n";
    return true;
}

bool DB::selectTable() {
    const char* sql = "SELECT * FROM person;";
    char* errmsg = nullptr;
    int rc = sqlite3_exec(db, sql, callback, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errmsg << "\n";
        sqlite3_free(errmsg);
        return false;
    }
    return true;
}

void DB::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
        std::cout << "Database closed.\n";
    }
}

DB::~DB() {
    close();
}

