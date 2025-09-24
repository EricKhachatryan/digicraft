#include <iostream>
#include "../header/add.h"
#include "../header/person.h"

int main(){	
std::cout << add(5,5) << std::endl;
person* p = new person();
p->print();
delete p;
return 0;
}
