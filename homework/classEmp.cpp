#include <iostream>
#include <string>

class Employee{
//Constructors/Destroctor
	public:
		Employee();
		Employee(std::string name , std::string surname, int salory);
		~Employee();
//Member functions
	public:
		void setName(std::string name);
		void setSurname(std::string surname);
		void setSalory(int salory);

		std::string getName();
		std::string getSurname();
		int getSalory();

		void print(){
			std::cout << "======:Employee info:======" << std::endl;
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Surname: " << this->surname << std::endl;
			std::cout << "Salory: " << this->salory << "$"<< std::endl;
		}
//Member Data
	private:
		std::string name;
		std::string surname;
		int salory;
};

Employee::Employee(){
	std::string name = "";
	std::string surname = "";
	int salory = 0;
}

Employee::Employee(std::string name , std::string surname , int salory){
	this->name = name;
	this->surname = surname;
	this->salory = salory;
}

Employee::~Employee(){

}

void Employee::setName(std::string name){this->name = name;}
void Employee::setSurname(std::string surname){this->surname = surname;}
void Employee::setSalory(int salory){this->salory = salory;}

std::string Employee::getName(){return this->name;}
std::string Employee::getSurname(){return this->surname;}
int Employee::getSalory(){return this->salory;}

int main(){
	Employee Emp("Eric","Khachatryan",1000);
	Emp.print();
	return 0;
}
