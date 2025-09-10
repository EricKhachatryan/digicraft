#include <iostream>
#include <exception>
#include <vector>


int main(){
	std::vector<int> vec = {1,2,3,4,5};
	try {
		int val = vec.at(4);
		std::cout << "number: " << val << std::endl;
	}catch(const std::out_of_range& e){
		std::cout << e.what() << std::endl;
	
	}	

	return 0;
}
