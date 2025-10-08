#include <iostream>
#include <sqlite3.h>
#include "../include/sqlutils.h"

int main(){
	sqlite3* db = nullptr;
	const std::string file = "my.db";
	const std::string name = "Eric";
	create(file,db);
	createTable(db);
	insert(db,name,23);
	selectTable(db);
	close(db);
}
