#ifndef _DB_H_
#define _DB_H_

#include <sqlite3.h>
#include <string>
#include <memory>

class DB {
private:
    static std::unique_ptr<DB> instance; 
    sqlite3* db = nullptr;

    DB() = default;

    DB(const DB&) = delete;
    DB& operator=(const DB&) = delete;

    static int callback(void* /*unused*/, int argc, char** argv, char** azColName);

public:
    static DB& getInstance();

    bool open(const std::string& filename);
    bool createTable();
    bool insert(const std::string& name, int age);
    bool selectTable();
    void close();

    ~DB();
};

#endif // _DB_H_

