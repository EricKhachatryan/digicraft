/*#include <iostream>
int main () { 
long int a = 1111111111111111111;
short int b = a;
std::cout << a << std::endl;
std::cout << b << std::endl;
return 0;
}

#include <iostream>
#include <string>
struct {
float radius; 
std::string color;
float weight;
} ball;

int main(){
	ball.radius = 5;
	ball.color = "Yellow";
	ball.weight = 10;
	std::cout << "color" << ball.color << std::endl;
	return 0;
}


#include <iostream>
#include <string>

struct persons {
int age;
std::string name;
std::string surname;
};

struct {
std::string brand;
int year;
std::string color;
}car1,car2; 

int main() {
persons p1;
p1.age = 23;
p1.name = "Eric";
p1.surname = "Khachatryan";
persons p2;
p2.age = 19;
p2.name = "Edul";
p2.surname = "Khachatryan";
std::cout << "Person 1\n" << "age: " << p1.age << std::endl;
std::cout << "name: " << p1.name << std::endl;
std::cout << "surname: " << p1.surname << std::endl;

std::cout << "Person 2\n" << "age: " << p2.age << std::endl;
std::cout << "name: " << p2.name << std::endl;
std::cout << "surname: " << p2.surname << std::endl;

car1.brand = "audi";
car1.year = 2001;
car1.color = "black";

car2.brand = "lada";
car2.year = 2015;
car2.color = "Yellow";


std::cout << "Car1\n" << "brand: " << car1.brand << std::endl;
std::cout << "year: " << car1.year << std::endl;
std::cout << "color: " << car1.color << std::endl;


std::cout << "Car2\n" << "brand: " << car2.brand << std::endl;
std::cout << "year: " << car2.year << std::endl;
std::cout << "color: " << car2.color << std::endl;
return 0;
}


#include <iostream>
#include <string>

struct group {
int age;
std::string name;
std::string surname;
};

int main () {
group student1;
student1.age = 19;
student1.name = "Mery";
student1.surname = "Asryan";

group student2;
student2.age = 25;
student2.name = "Valod";
student2.surname = "Voskanyan";

group student3;
student3.age = 21;
student3.name = "Gevor";
student3.surname = "Asatryan";

group student4;
student4.age = 22;
student4.name = "Gor";
student4.surname = "Asryan";

group student5;
student5.age = 23;
student5.name = "Eric";
student5.surname = "Khachatryan";

group student6;
student6.age = 23;
student6.name = "Karen";
student6.surname = "Hakobjanyan";

std::cout << "C++ CLASS\n" << "Student1" << std::endl;
std::cout << "age: " << student1.age << std::endl;
std::cout << "name: " << student1.name << std::endl;
std::cout << "surname: " << student1.surname << std::endl;

std::cout << "Student2" << std::endl;
std::cout << "age: " << student2.age << std::endl;
std::cout << "name: " << student2.name << std::endl;
std::cout << "surname: " << student2.surname << std::endl;

std::cout << "Student3" << std::endl;
std::cout << "age: " << student3.age << std::endl;
std::cout << "name: " << student3.name << std::endl;
std::cout << "surname: " << student3.surname << std::endl;

std::cout << "Student4" << std::endl;
std::cout << "age: " << student4.age << std::endl;
std::cout << "name: " << student4.name << std::endl;
std::cout << "surname: " << student4.surname << std::endl;

std::cout << "Student5" << std::endl;
std::cout << "age: " << student5.age << std::endl;
std::cout << "name: " << student5.name << std::endl;
std::cout << "surname: " << student5.surname << std::endl;

std::cout << "Student6" << std::endl;
std::cout << "age: " << student6.age <<std::endl;
std::cout << "name: " << student6.name <<std::endl;
std::cout << "surname: " << student6.surname <<std::endl;

return 0;
}
*/


#include <iostream>
#include <string>

struct student {
std::string name;
std::string surname;
};
struct xumb {
	std::string name;
	student student1;
	student student2;
	student student3;
	student student4;
	student student5;
};
struct bajin {
	std::string name;
	xumb vmsh105b;
};
struct ambion {
	std::string name;
	bajin mexanik;
};

struct hamalsaran {
	std::string name;
	std::string city;
ambion mexanika;
};

int main(){
student1.name = "Tigran";
student1.surname = "Axababyan";
student2.name = "Ernani";
student2.surname = "Araqelyan";
student3.name = "Eric";
student3.surname = "Khachatryan";
student4.name = "Arthur";
student4.surname = "Pogosyan";
student5.name = "Sarqis";
student5.surname = "Galechyan";
vmsh105b.name = "vmsh105b"; 
mexanik.name = "mexanik";
mexanika.name = "mexanikakan";
hamalsaran.name = "NPUA";
hamalsaran.city = "Vanadzor";
return 0;
}



















