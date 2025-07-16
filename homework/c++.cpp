
#include <iostream>
#include <string>
/*
int foo(int a, int b, int c) {
    int min = a;

    if (b < min) {
        min = b;
    }

    if (c < min) {
        min = c;
    }

    return min;
}

int main() {
    int a, b, c;
    std::cout << "input a,b,c" << std::endl;

    std::cin >> a >> b >> c;
    std::cout << "min: " << foo(a, b, c) << std::endl;
    return 0;
}


int main(){
	int sum = 0;
	int a = 0;
	std::cin >> a;
	int* arr = new int[a];
	for(int i = 0; i < a; ++i){
		std::cin >> arr[i];
		sum += arr[i];
	}
	std::cout << "sum = " << sum << std::endl;
	delete[] arr;
	return 0;
}

class book{
	public:
		book() : title(""), author(""), year(0) {}

		book(std::string title,std::string author, int year) : title(title), author(author), year(year) {}

		~book() {}
	public:
		void setTitle(std::string title){this->title = title;}
		void setAuthor(std::string author){this->author = author;}
		void setYear(int year){this->year = year;}
		std::string getTitle(){return this->title;} 
		std::string getAuthor(){return this->author;}
		int getYear(){return this->year;}
		
		void printinfo(){
			std::cout << "Title :" << this->title << std::endl;
			std::cout << "Author :" << this->author << std::endl;
			std::cout << "Year :" << this->year << std::endl;

		}
	
	private:
		std::string title;
		std::string author;
		int year;

};




int main(){

book b;
b.printinfo();
	return 0;
}

int main(){
	int age;
	std::string name;
	std::cin >> name;
	std::cin >> age;
	std::cout << "привет меня зовут " <<  name << "мне " << age << "лет";

	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	
	std::cout << a + b << std::endl; 
	
	if (a < b){
		std::cout << b - a << std::endl; 
	}else{
		std::cout << a - b << std::endl; 
	}
	
	
	std::cout << a * b  << std::endl; 

	std::cout << b - a << std::endl; 

	return 0;
}

void input( int& a,int& b){
	std::cin >> a;
	std::cin >> b;
}

int sum(const int& a, const int& b){return a + b;}

void output(const int& result){std::cout << result << std::endl;}

int main(){
	int a = 0;
	int b = 0;
	int result = 0;
	input(a,b); 
	result = sum(a,b);
	output(result);

	return 0;
}



	enum Weekday {
		Monday,
    		Tuesday,
    		Wednesday,
    		Thursday,
    		Friday,
    		Saturday,
    		Sunday,

	};	

int main (){
	int num = 0;
	std::cout << "inpute num 0-6 : ";
	std::cin >> num;
	enum Weekday day = static_cast<Weekday>(num);
	
	
	switch (day){
		case Monday :
			std::cout << "Monday" << std::endl;
			break;

		case Tuesday :
			std::cout << "Tuesday" << std::endl;
			break;
		
		case Wednesday :
			std::cout << "Wednesday" << std::endl;
			break;
		
		case Thursday :
			std::cout << "tursday" << std::endl;
			break;
		
		case Friday :
			std::cout << "Friday" << std::endl;
			break;
		
		case Saturday :
			std::cout << "saturday" << std::endl;
			break;

		case Sunday :
			std::cout << "Sunday" << std::endl;
			break;
		
		default :
			std::cout << "def" << std::endl;
			break;
	}




return 0;
}

*/

struct Student {
	std::string name;
	int age;
	char grade;

};

void printStudent(const Student &s){
	
	std::cout << "student : " << s.name << std::endl;
	std::cout << "age : " << s.age << std::endl;
	std::cout << "grade : " << s.grade << std::endl;
}

int main () {
Student student[3];
for(int i = 0; i < 3;++i){
std::cout << "input name age grade : " << std::endl;
std::cin >> student[i].name >> student[i].age >> student[i].grade;
}
for (int i = 0; i < 3; ++i){
printStudent(student[i]);
}
return 0;
}













