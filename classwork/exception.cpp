#include <iostream>
#include <exception>

int devaid(int a, int b){
return a/b;
}
int main(){
	int a = 10;
	int b = 0;

	try{
	if( b == 0 ){
		throw "Division by 0 Exception";
	}
		std::cout << devaid(a,b) << std::endl;	
	}catch( const char* msg){
		std::cout << "Error " << msg << std::endl;
	}

	return 0;	
}
