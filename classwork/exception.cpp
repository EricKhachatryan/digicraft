#include <iostream>
#include <exception>

/*
int devaid(int a, int b){
if( b == 0 ){
	throw "Division by 0 Exception";
	}
return a/b;
}
int main(){
	int a = 10;
	int b = 2;
	try{
		std::cout << devaid(a,b) << std::endl;	
	}catch( const char* msg){
		std::cout << "Error " << msg << std::endl;
	}

	return 0;	
}

*/

class MyException : public std::exception {
public: 
	const char* what( ) const noexcept override {
		return "My Exception";
	}


};

void f(){
	std::cout << "MyException" << std::endl;
	throw new MyException();
}

void a(){
	std::cout << "exception" << std::endl;
	throw new std::exception();
}

int main(){
	try{
		f();
		a();
	} catch ( const std::exception* e ){
		std::cout << "Error: " << e->what() << std::endl;
	}

	return 0;
}










