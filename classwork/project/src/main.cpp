#include <iostream>
#include "../include/add.h"
#include "../include/person.h"

int main(){
int a = 5;
int b = 9;
std::cout << "resault = " << add(a,b) << std::endl;	
std::cout << "eric " << std::endl;
Person* p = new Person();
p->print();
delete p;
return 0;
}
