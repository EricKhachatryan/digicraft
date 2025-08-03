#include <iostream>
#include <string>

class Shape{
	public:
		Shape(){}
	~Shape(){}
		virtual void area(){
			std::cout << "" << std::endl;
		}
}; 

class Rectangle : public Shape{
	public:
		void area(){
			std::cout << "rectangle area" << std::endl;
		}
		};

class Triangle : public Shape{
	public:
		void area(){
			std::cout << "TREANGLE area" << std::endl;
		}
};
int main(){
	Shape* sh = new Rectangle();	
	sh->area();
	Shape* s = new Triangle();
	s->area();
	return 0;
}
