#include "../include/db.h"

int main() {
    DB& db = DB::getInstance();

    if (!db.open("Database.db"))
        return 1;

    db.createTable();
    db.insert("Eric", 24);
    db.insert("AAAA", 30);

    db.selectTable();
    db.close();

    return 0;
}

