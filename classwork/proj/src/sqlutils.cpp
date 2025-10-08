#include <sqlite3.h>
#include <iostream>
#include <stdexcept>
#include "../include/sqlutils.h"

static int callback(void* /*unused*/,int argc, char** argv, char** azColName) {
	for(int i = 0; i < argc;++i){
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " | ";
	}
	std::cout << "\n";
	return 0;
}

int create(const std::string filename, sqlite3*& db){
	int rc = sqlite3_open(filename.c_str(), &db);
	if(rc != SQLITE_OK){
		std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << "\n";
		sqlite3_close(db);
		return 1;
	}
	return 0;
}

bool createTable(sqlite3*& db) { 
	const char* command = "CREATE TABLE IF NOT EXISTS person(id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
	char* errmsg = nullptr;
	rc = sqlite3_exec(db,command,callback,nullptr,&errmsg);
	if(rc != SQLITE_OK){
		std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << "\n";
		sqlite3_free(errmsg);
		return false;
	
	}
}

bool insert(sqlite3*& db, const std::string& name,const int& age){ 
	const char* command = 
        	"INSERT INTO person(name,age) VALUES ('%name', 30), ('Bob', 25);";
	char* errmsg = nullptr;
	rc = sqlite3_exec(db,command,callback,nullptr,&errmsg);
	if(rc != SQLITE_OK){
		std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << "\n";
		sqlite3_free(errmsg);
		return false;
	
	}
}

int selectTable(sqlite3*& db); 
	const char* command = 
        	"SELECT id, name, age FROM person;";
	char* errmsg = nullptr;
	rc = sqlite3_exec(db,command,callback,nullptr,&errmsg);
	if(rc != SQLITE_OK){
		std::cerr << "Can't open DB: " << sqlite3_errmsg(db) << "\n";
		sqlite3_free(errmsg);
		return false;
	
	}

}
void close(sqlite3*& db){
	sqlite3_close(db);
}






