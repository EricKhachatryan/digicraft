#include <iostream>
#include <memory>

class Person{
public:
	Person(){
		std::cout << "constructor" << std::endl;
	}

	~Person(){
		std::cout << "destructor" << std::endl;
	}

};

class Node {
private:
	std::shared_ptr<Node> next;
	std::weak_ptr<Node> prev;

};

int main(){
	//Unique
	//std::unique_ptr<Person> uPtr = std::make_unique<Person>();
	//auto p = std::move(uPtr);
	
	//Shared
	//std::shared_ptr<Person> sPtr = std::make_shared<Person>();
	//std::cout << sPtr.use_count() << std::endl;
	//{
	//auto p = sPtr;
	//std::cout << p.use_count() << std::endl;
	//}
	
	//Weak
	
	return 0;
}



