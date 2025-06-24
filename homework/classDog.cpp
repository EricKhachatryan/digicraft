#include <iostream>
#include <string>

class Dog{
//Constructors/Destructor
	public:
		Dog();
		Dog(std::string breed , std::string name , int age);
		~Dog();
//Member Functions
	public:
		void setBreed(std::string breed);
		void setName(std::string name);
		void setAge(int age);
		std::string getBreed();
		std::string getName();
		int getAge();
		
		void print(){
			std::cout << "=====:Dog info:======" << std::endl;
			std::cout << "Breed: " << this->breed << std::endl;
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Age: " << this->age << std::endl;
		}
//Member Data
	private:	
		std::string breed;
		std::string name;
		int age;
};

Dog::Dog(){
	std::string breed = "";
	std::string name = "";
	int age = 0;
}

Dog::Dog(std::string breed , std::string name , int age){
this->breed = breed;
this->name = name;
this->age = age;
}

Dog::~Dog(){

}

void Dog::setBreed(std::string breed){this->breed = breed;}
void Dog::setName(std::string name){this->name = name;}
void Dog::setAge(int age){this->age = age;}

std::string Dog::getBreed(){return this->breed;}
std::string Dog::getName(){return this->name;}
int Dog::getAge(){return this->age;}


int main(){
	Dog D("Rottweiler","Bob",7);
	D.print();
	return 0; 
}
