#ifndef _DB_WRAPPER_
#define _DB_WRAPPER_

#include <string>
#include <stdexcept>
#include <sqlite3.h>

class DBWrapper {
public:
	explicit DBWrapper(const std::string&);
	
	~DBWrapper();

	DBWrapper( const DBWrapper& ) = delete;
	DBWrapper& operator = (const DBWrapper& ) = delete;
		
	void execute( const std::string& sql);

	sqlite3_stmt* prepare (const std::string& sql);

	void beginTransaction();

	void commit();

	void rollback();

	sqlite3* raw();

private:
	sqlite3* db;

};

#endif //_DB_WRAPPER_

