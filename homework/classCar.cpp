#include <iostream>
#include <string>

class Car {
//Constructors:
	public:
		Car();
		Car( std::string mark , std::string color , int year );
		~Car();
//Member functions: 
	public:
		void setMark(std::string mark);
		void setColor(std::string color);
		void setYear(int year);
		std::string getMark();
		std::string getColor();
		int getYear();
		
		void print(){
			std::cout << "======:Car Info:======" << std::endl;
			std::cout << this->mark << std::endl;
			std::cout << this->color << std::endl;
			std::cout << this->year << std::endl;
			}

//Member Data
	private:
		std::string mark;
		std::string color;
		int year;


};

Car::Car(){
	this->mark = "";
	this->color = "";
	this->year = 0;
}

Car::Car( std::string mark , std::string color , int year ){
	this->mark = mark;
	this->color = color;
	this->year = year;
}

Car::~Car(){

}

void Car::setMark(std::string mark){
	this->mark = mark;
};

void Car::setColor(std::string color){
	this->color = color;
};

void Car::setYear(int year){
	this->year = year;
};

std::string Car::getMark(){
	return this->mark;
};

std::string Car::getColor(){
	return this->color;
};

int Car::getYear(){
	return this->year;
};




int main(){
	Car C("Audi","Black",2005);
	C.print();
	C.setMark("BMW");
	C.setColor("White");
	C.setYear(2001);
	C.print();
	return 0;
}
