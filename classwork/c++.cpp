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


#include <iostream>
#include <string>

struct student {
	std::string name = "";
	int mark = 0;
};

bool isPussed( int num ){
bool bNum = false;
	if (num >= 51){
	bNum = true;
		return bNum;
}
else {
	return bNum;
}
}


int main( )
{
student st;
std::cin >> st.name;
std::cin >> st.mark;
bool answer = isPussed(st.mark);
if( answer == true ){
std::cout << st.name << " pussed " << std::endl;
}
else{
std::cout << st.name << " failed " << std::endl;

}
	return 0;
}

#include <iostream>
#include <string>

int add( int a , int b ){
return a + b;
}
float add( float a , float b ) {
return a + b;
}
double add( double a , double b ) {
return a + b;
}

int main( ) {
std::cout << add( 7 , 7 ) << std::endl;
std::cout << add( 2.5f , 5.5f ) << std::endl;
std::cout << add( 2.684695654d , 2.656516561d ) << std::endl;
	return 0;
}


#include <iostream>
#include <string>

struct Student {
	std::string name;
	int grade;
};

struct Employee {
	std::string name;
	int salory;
};

void printinfo(Student);
void printinfo(Employee);

int main( ){ 

Student st;
	st.name = "Eric";
	st.grade = 50;

Employee emp;
	emp.name = "Eric";
	emp.salory = 150000;

printinfo(st);
printinfo(emp);

return 0;
}

void printinfo(Student st) {
	std::cout << "Student Name = " << st.name << "\nStudent Grade = " << st.grade << std::endl;
} 

void printinfo(Employee emp) {
	std::cout << "Employee Name = " << emp.name << "\nEmployee Grade = " << emp.salory << std::endl;
}


#include <iostream>
#include <string>

int fact(int);

int main (){
int num = 0;
std::cin >> num;
if ( num >= 0 ){
	std::cout << fact(num) << std::endl;
}
	return 0;
}

int fact(int num){
if (  num == 1 )
{
	return 1;
}

return num * fact(num -1);
}

#include <iostream>
#include <string>

int fib(int);

int main (){
int num = 0;
std::cin >> num;
if ( num > 0 ){
	std::cout << fib(num) << std::endl;
}
	return 0;
}

int fib(int num){
if( num == 1 || num == 2 ) {
return 1;
}
return fib( num - 1 ) + fib( num - 2 );
}

#include <iostream>
#include <string>

int sum(int);

int main(){
	int num = 0;
	std::cout << "Input Number = ";
	std::cin >> num;
	if(num >= 0){
		std::cout << sum(num) << std::endl;
       	}
	return 0;
}

int sum(int n){
	if( n > 0 ){
		std::cout << "aa" << std::endl;
		return ( n % 10) + sum( n / 10 );
	}else
return 0;
}


#include <iostream>
#include <string>

int main(){
int* p = nullptr;
	std::cout << *p << std::endl;


	return 0;
}

#include <iostream>
#include <string>

int main(){
int a = 5;
int& r = a;
std::cout << r << &r << &a << std::endl;
	
	return 0;
}



#include <iostream>
#include <string>

 struct student{
	std::string* name = nullptr;
	int* grade = nullptr;	
};

int main(){
	student* mystruct = new student();
	mystruct->name = new std::string ("Eric");
	mystruct->grade = new int(50);
	std::cout << *(mystruct->name) << *(mystruct->grade) << std::endl;
delete mystruct->name;	
delete mystruct->grade;	
delete mystruct;	
	
	
	
	int a = 5;
	int& r = a;
	r = 10;
	std::cout << r << std::endl;
	
	return 0;
}



#include <iostream>
#include <string>

int main(){
int arr[3][3] = {
	{1,2,3},
	{4,5,6},
	{7,8,9},
		};
for(int i = 0; i < 3;++i){
	for(int j = 0 ; j < 3 ;++j){
		std::cout << *(*(arr + i)+j) << std::endl;	
}
}

int arr1[10] ={0,1,2,3,4,5,6,7,8,9};
for(int i = 0; i < 10 ;++i){ 
		std::cout << *(arr1 + i)  << std::endl;	
}
int size = sizeof(arr1) / sizeof(arr1[0]);
		std::cout << size  << std::endl;	
return 0;
}


#include <iostream>
#include <string>

int main(){

int* arr = new int[5];	
for(int i = 0 ; i < 5;++i){
	std::cin >> *(arr + i);
}
	
for(int i = 0 ; i < 5;++i){
	std::cout << *(arr + i) << std::endl;
}

	return 0;
}


#include <iostream>
#include <string>

void dArr( int row , int column );

int main(){

	dArr( 3 , 3 );
	
	return 0;
}

void dArr( int row , int column ){
int** arr = new int* [row];
for(int i = 0 ; i < row ; ++i){
arr[i] = new int [column];
}
}; 



#include <iostream>
#include <string>

class Student {
	public:
		void setName(std::string name);	
		std::string getName();	
	
		void setSurname(std::string surname);	
		std::string getSurname();
	
		void setAge(int age);	
		int getAge();
void print(){
	std::cout << getName() << std::endl;
	std::cout << getSurname() << std::endl;
	std::cout << getAge() << std::endl;
}
	private:
		std::string m_name;
		std::string m_surname;	
		int m_age;

};

void Student::setName(std::string name){
	m_name = name;
}
std::string Student::getName(){
	return m_name;
}

void Student::setSurname(std::string surname){
	m_surname = surname;
}
std::string Student::getSurname(){
	return m_surname;
}
void Student::setAge(int age){
	m_age = age;
}
int Student::getAge(){
	return m_age;
}



int main(){
	Student st;
	st.setName("Eric");
	st.setSurname("Khachatryan");
	st.setAge(23);
	std::cout << "Student Info:" << std::endl;
	st.print();
	return 0; 
}



#include <iostream>
#include <string>

class Person {
	public:
		Person(){
			std::string name = "";
			int age = 0;
		}
		Person(std::string name , int age){
			this->name = name;
			this->age = age;
		}
		~Person(){
		
		}
	public:
		void setName(std::string name){this->name = name;}
		void setAge(int age){this->age = age;}
		std::string getName(){return this->name;}
		int getAge(){return this->age;}
		void printinfo(){
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Age: " << this->age << std::endl;
		}

	protected:
		std::string name;
		int age;
};

class Student : public Person {
	public:
		Student(){
			std::string name = "";
			int age = 0;
			int grade = 0;
		}
		Student(std::string name , int age , int grade){
			this->name = name;
			this->age = age;
			this->grade = grade;
		}
		~Student(){
		
		}
	public:
		void setGrade(int grade){this->grade = grade;}
		int getGrade(){return this->grade;}

		void printinfo(){
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Age: " << this->age << std::endl;
			std::cout << "Grade: " << this->grade << std::endl;
			
		}
	private:
		int grade;
		


};


class Teacher : public Person {
	public:
		Teacher(){
			std::string name = "";
			int age = 0;
			std::string lecture = "";
		}
		Teacher(std::string name , int age , std::string lecture){
			this->name = name;
			this->age = age;
			this->lecture = lecture;
		}
		~Teacher(){
		
		}
	public:
		void setLecture(std::string lecture){this->lecture = lecture;}
		std::string getLecture(){return this->lecture;}

		void printinfo(){
			std::cout << "Name: " << this->name << std::endl;
			std::cout << "Age: " << this->age << std::endl;
			std::cout << "Lecture: " << this->lecture << std::endl;
			
		}
	private:
		std::string lecture;
		


};

int main(){
Person p("Eric",23);
	p.printinfo();
Student st("Er",20,100);
	st.printinfo();
Teacher t("Kim",24,"c++");	
	t.printinfo();
return 0;
}



#include<iostream>
#include <string>

class Animal{
	public:
		virtual	void sound(){std::cout << "Unknow" << std::endl;}
};

class Fish : public Animal{
	public:
		virtual void foo(){
			std::cout << "foo" << std::endl;
		}
};
class Fish1 : public Fish{
	public:
		void foo(){
			std::cout << "foo1" << std::endl;
		}
};

class Fish2 : public Fish{
	public:
		void foo(){
			std::cout << "foo2" << std::endl;
		}
};

class Fish3 : public Fish{
	public:
		void foo(){
			std::cout << "foo3" << std::endl;
		}
};

class Cat : public Animal{
	public:
		void sound(){std::cout << "cat sount" << std::endl;}
};

class Dog : public Animal{
	public:
		void sound(){std::cout << "dog sound" << std::endl;}
};

class Horse : public Animal{
	public:
		void sound(){std::cout << "horse sound" << std::endl;}
};

int add(){
int a = 0;
int b = 0;
return a + b;
}
int add(int a, int b){
return a + b;
}

int main(){
Animal* anim[4]; 
anim[0] = new Animal;
anim[1] = new Cat;
anim[2] = new Dog;
anim[3] = new Horse;
for(int i = 0;i <= 3; i++){
anim[i]->sound();
}
Fish* fish[3];
fish[0] = new Fish1;
fish[1] = new Fish2;
fish[2] = new Fish3;
for(int i = 0;i < 3; i++){
fish[i]->foo();
}

std::cout << add() << std::endl;
std::cout << add(5,5) << std::endl;

return 0;
}



#include<iostream>
#include<string>

//Pass by

void fooValue(int num){
num += 1;
std::cout << num << std::endl;
}

void fooRef(int& num){
num += 1;
std::cout << num << std::endl;
}

void fooPointer(int* num){
*num += 1;
std::cout << *num << std::endl;
}

// Return

int fooRetVal(int num){
	num += 1;
	return num;
}

int& fooRetRef(int num){
	num += 1;
	return num;
}

int* fooRetPoint(int num){
num += 1;
	return &num;
}

int main(){

	int mynum = 5;
//Pass by

	fooValue(mynum);
	std::cout << mynum << std::endl;
	
	fooRef(mynum);
	std::cout << mynum << std::endl;

	fooPointer(&mynum);
	std::cout << mynum << std::endl;

//Return

	std::cout << fooRetVal(mynum) << std::endl;
	std::cout << fooRetRef(mynum) << std::endl;
	std::cout << fooRetPoint(mynum) << std::endl;


	return 0;
}


#include<iostream>
#include<string>

class Animal {
	public:
		Animal(std::string& name) : name(name){
		}
		~Animal(){}
	public:
		std::string getName(){
		return this->name;
		}
	protected:
		const std::string name;
};

class Fish : public Animal {
	public:
		Fish(std::string& name, int size) : Animal(name), size(size) {
		}
		~Fish(){}
	public:
		int getSize(){
		return this->size;
		}
	protected:
		int size;
};

class Shark : public Fish{
	public:
		Shark(std::string& name,int size,int weight) : Fish(name,size) , weight(weight){
		}
		~Shark(){}
	public: 
		int getWeight(){
		return this->weight;
		}
	private:
		int weight;
};


int main(){
	std::string name = "fishh";
	Shark s(name,100,50); 
	std::cout << s.getName() << s.getSize() << s.getWeight() << std::endl;
	return 0;
}

*/

























