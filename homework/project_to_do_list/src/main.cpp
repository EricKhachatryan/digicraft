#include "../include/db_wrapper.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

void print_usage() {
    std::cout << "Usage:\n";
    std::cout << "  ./todo addcat <name>\n";
    std::cout << "  ./todo addtodo <title> <category> <YYYY-MM-DD>\n";
    std::cout << "  ./todo list [--all|--pending|--category=<cat>]\n";
    std::cout << "  ./todo complete <id>\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    try {
        DBWrapper db("todo.db");

        std::string command = argv[1];

        if (command == "addcat" && argc == 3) {
            std::string name = argv[2];
            sqlite3_stmt* stmt = db.prepare("INSERT INTO categories (name) VALUES (?);");
            sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
            if (sqlite3_step(stmt) == SQLITE_DONE) {
                std::cout << "Category '" << name << "' added\n";
            }
            sqlite3_finalize(stmt);
        }
        else if (command == "addtodo" && argc == 5) {
            std::string title = argv[2];
            std::string category = argv[3];
            std::string due_date = argv[4];

            db.beginTransaction();
            try {
                // Проверяем, существует ли категория
                sqlite3_stmt* stmt = db.prepare("SELECT id FROM categories WHERE name = ?;");
                sqlite3_bind_text(stmt, 1, category.c_str(), -1, SQLITE_STATIC);
                int category_id = -1;
                if (sqlite3_step(stmt) == SQLITE_ROW) {
                    category_id = sqlite3_column_int(stmt, 0);
                }
                sqlite3_finalize(stmt);

                // Если категория не существует, создаём её
                if (category_id == -1) {
                    stmt = db.prepare("INSERT INTO categories (name) VALUES (?);");
                    sqlite3_bind_text(stmt, 1, category.c_str(), -1, SQLITE_STATIC);
                    if (sqlite3_step(stmt) != SQLITE_DONE) {
                        throw std::runtime_error("Failed to create category");
                    }
                    category_id = sqlite3_last_insert_rowid(db.raw());
                    sqlite3_finalize(stmt);
                }

                // Добавляем задачу
                stmt = db.prepare("INSERT INTO todos (title, category_id, due_date) VALUES (?, ?, ?);");
                sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_STATIC);
                sqlite3_bind_int(stmt, 2, category_id);
                sqlite3_bind_text(stmt, 3, due_date.c_str(), -1, SQLITE_STATIC);
                if (sqlite3_step(stmt) == SQLITE_DONE) {
                    std::cout << "Todo " << sqlite3_last_insert_rowid(db.raw()) << " added\n";
                }
                sqlite3_finalize(stmt);

                db.commit();
            } catch (...) {
                db.rollback();
                throw;
            }
        }
        else if (command == "list" && argc <= 3) {
            std::string query = "SELECT t.id, t.title, c.name, t.due_date, t.done "
                               "FROM todos t JOIN categories c ON t.category_id = c.id";
            if (argc == 3) {
                std::string option = argv[2];
                if (option == "--all") {
                    // Без изменений
                } else if (option == "--pending") {
                    query += " WHERE t.done = 0";
                } else if (option.find("--category=") == 0) {
                    std::string category = option.substr(11);
                    query += " WHERE c.name = ?";
                } else {
                    print_usage();
                    return 1;
                }
            } else {
                query += " WHERE t.done = 0"; // По умолчанию показываем незавершённые
            }

            sqlite3_stmt* stmt = db.prepare(query + ";");
            if (argc == 3 && std::string(argv[2]).find("--category=") == 0) {
                std::string category = std::string(argv[2]).substr(11);
                sqlite3_bind_text(stmt, 1, category.c_str(), -1, SQLITE_STATIC);
            }

            while (sqlite3_step(stmt) == SQLITE_ROW) {
                int id = sqlite3_column_int(stmt, 0);
                const unsigned char* title = sqlite3_column_text(stmt, 1);
                const unsigned char* category = sqlite3_column_text(stmt, 2);
                const unsigned char* due_date = sqlite3_column_text(stmt, 3);
                int done = sqlite3_column_int(stmt, 4);
                std::cout << id << " | " << (title ? reinterpret_cast<const char*>(title) : "")
                          << " | " << (category ? reinterpret_cast<const char*>(category) : "")
                          << " | " << (due_date ? reinterpret_cast<const char*>(due_date) : "")
                          << " | " << (done ? "done" : "pending") << "\n";
            }
            sqlite3_finalize(stmt);
        }
        else if (command == "complete" && argc == 3) {
            int id = std::stoi(argv[2]);
            sqlite3_stmt* stmt = db.prepare("UPDATE todos SET done = 1 WHERE id = ?;");
            sqlite3_bind_int(stmt, 1, id);
            if (sqlite3_step(stmt) == SQLITE_DONE && sqlite3_changes(db.raw()) > 0) {
                std::cout << "Marked " << id << " done\n";
            } else {
                std::cout << "Todo " << id << " not found\n";
            }
            sqlite3_finalize(stmt);
        }
        else {
            print_usage();
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
