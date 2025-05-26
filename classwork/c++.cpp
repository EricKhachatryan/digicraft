/*
#include <iostream>
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


#include <iostream>
#include <string>

struct student {
	std::string name;
	int grade;
};

int main(){
student st;
std::cout << "Input student name" << std::endl;
std::cin >> st.name;
std::cout << "Input student grade" << std::endl;
std::cin >> st.grade;
if( st.grade < 0 ){
	std::cout << "grade negative" << std::endl;
	return 1;
    	}
if( st.grade <= 40 && st.grade >= 0){
	std::cout << "name = " << st.name << "\ngrade = D" << std::endl;
}else if( st.grade <= 60 && st.grade > 40 ) {
std::cout << "name = " << st.name << "\ngrade = C" << std::endl;
}else if( st.grade <= 80 && st.grade > 60 ) {
std::cout << "name = " << st.name << "\ngrade = B" << std::endl;
}else{
std::cout << "name = " << st.name << "\ngrade = A" << std::endl;
}
return 0;
}


#include <iostream>
#include <string>
struct employee{
	std::string name;
	int salary;
	int experience;
};
int main (){
	float sum = 0;
	employee emp;
	std::cout << "Input name" << std::endl;
	std::cin >> emp.name;
	std::cout << "Input salary" << std::endl;
	std::cin >> emp.salary;
	std::cout << "Input experience" << std::endl;
	std::cin >> emp.experience;
if ( emp.salary < 0 || emp.experience < 0){
	std::cout << "salary or experience negative" << std::endl;
return 1;
}
	if(emp.experience <= 2){
	 sum = emp.salary * 5 / 100;
	std::cout << "name = " << emp.name << "\nsum = " << sum << std::endl;
	}else if(emp.experience > 2 && emp.experience <= 5 ){
	sum = emp.salary * 10 / 100;
	std::cout << "name = " << emp.name << "\nsum = " << sum << std::endl;
	}else
	sum = emp.salary * 15 / 100;
	std::cout << "name = " << emp.name << "\nsum = " << sum << std::endl;
	return 0;
}

#include <iostream>
#include <string>
int main (){
	std::cout << "input number" << std::endl;
	std::cin >> num;
	int num = 0;
switch (num){
	case 1:
		std::cout << "Hashvapahutyun" << std::endl;
		break;
	case 2:
		std::cout << "Vacharq" << std::endl;
		break;
	case 3:
		std::cout << "Tnoren" << std::endl;
		break;
	case 4:
		std::cout << "Hr" << std::endl;
		break;
	case 5:
		std::cout << "Srah" << std::endl;
		break;
	case 6:
		std::cout << "Araqum" << std::endl;
		break;
	case 7:
		std::cout << "Operator" << std::endl;
		break;
	case Default :		
		std::cout << "Default" << std::endl;
		break;

}	
return 0;
}




#include <iostream>
#include <string>
enum office{
HASHVAPAHUTYUN,
VACHARQ,
TNOREN,
HR,
SRAH,
ARAQUM,
OPERATOR,
DEFAULT
};

int main(){
	enum office off = OPERATOR;
switch (off){

	case HASHVAPAHUTYUN :
		std::cout << "Hashvapahutyun" << std::endl;
		break;
	case VACHARQ :
		std::cout << "Vacharq" << std::endl;
		break;
	case TNOREN  :
		std::cout << "Tnoren" << std::endl;
		break;
	case HR :
		std::cout << "Hr" << std::endl;
		break;
	case SRAH :
		std::cout << "Srah" << std::endl;
		break;
	case ARAQUM  :
		std::cout << "Araqum" << std::endl;
		break;
	case OPERATOR :
		std::cout << "Operator" << std::endl;
		break;
	case DEFAULT :		
		std::cout << "Default" << std::endl;
		break;
}
	return 0;
}

include <iostream>
include <string>
enum bc{
PLUS,
MINUS,
BAZMAPATKUM,
BAJANUM,
DEFAULT
};
int main(){

int num1 = 0;
int num2 = 0;
char operator;


std::cout << "input number 1" << std::endl;
		std::cin >> num1;
std::cout << "input operator" << std::endl;
		std::cin >> operator;
std::cout << "input number 2" << std::endl;
		std::cin >> num2;
if()	

switch(calculator){	

	case PLUS :
		std::cout << "Srah" << std::endl;
		break;
	case MINUS :
		std::cout << "Srah" << std::endl;
		break;
	case BAZMAPATKUM :
		std::cout << "Araqum" << std::endl;
		break;
	case BAJANUM :
		std::cout << "Operator" << std::endl;
		break;
	case DEFAULT :		
		std::cout << "Default" << std::endl;
		break;
}

return 0;
}



#include <iostream>
#include <string>

int main() {
for(int i = 0; i < 10 ; i++){
	std::cout << i << std:endl;
}



int i = 0;
while (i < 10) {
	std::cout << i << std:endl;
i++;
}

int i = 0; 
do{
	std::cout << i << std:endl;
i++;
}while(i < 10);

return 0;
}



#include <iostream>
#include <string>

int main (){
    for (int i = 0; i < 3 ; i++){
	std::string login = "";
    std::string password = "";
		std::cout << "input login" << std::endl;
		std::cin >> login ;  
		std::cout << "input password" << std::endl;
		std::cin >> password ;
	      if(login == "eric"){ 
		std::cout << "input password" << std::endl;
		std::cin >> password ;
		      if(password == "123"){
		std::cout << "login successfuly" << std::endl;
		      break;
		      }
		      else 
		std::cout << "password false" << std::endl;

	      } 
	      else 	      
		std::cout << "login false" << std::endl;
}
	return 0;
}

#include <iostream>
#include <string>

enum eQuiz { MATH, ENGL, PROG }; 

int main(){
std::string math = "";
std::string engl = "";
std::string prog = "";
std::string amath = "2";
std::string aengl = "lenguage";
std::string aprog = "c++";
int sum = 0;
int iQuiz = 0;
for(iQuiz = 0; iQuiz < 3 ;iQuiz++ ){
	eQuiz quiz = static_cast<eQuiz>(iQuiz);
	
	switch( iQuiz ){
		case MATH:
	std::cout << "math question" << std::endl;
	std::cout << "1 + 1 = ";
	std::cin >> math;
	if(math == amath){
		sum++;
	continue;
	}else
		continue;

		case ENGL:
	std::cout << "engl question" << std::endl;
	std::cout << "engl = ";
	std::cin >> engl;
	if(engl == aengl){
		sum++;
	continue;
	}else
		continue;
		case PROG:
	std::cout << "prog question" << std::endl;
	std::cout << "program leng = ";
	std::cin >> prog;
	if(prog == aprog){
		sum++;
	continue;
	}else
		continue;

}

}

	std::cout << sum << "/3" << std::endl;



return 0;
}

#include <iostream>
#include <string>

int sum(  ){
int i = 1;
int num = 0;
for( i; i <= 10 ; i++){
num = num + i;
num += i;
}
	return num;
}

int main( ) {
	std::cout << sum() << std::endl;
	return 0;
}


#include <iostream>
#include <string>

int personinfo( ){
	std::string name = "";
	std::string surname = "";
	int age = 0;
	std::cin >> name;
	std::cin >> surname;
	std::cin >> age;
	std::cout << name << surname << age << std::endl;
return 0;
}
 
int main(){
personinfo();
	return 0;
}

*/














