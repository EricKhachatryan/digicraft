
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


int main (){
	int x = 0;
	std::cin >> x ;
	if(x > 0){
		std::cout << "positive" << std::endl;
	}else if(x < 0){
		std::cout << "negative" << std::endl;
	}else
		std::cout << "zero" << std::endl;
	int sum = 0;
	int n = 0;
	std::cin >> n;
	for (int i = 1;i <= n;i++){
		sum += i;	
	}
	std::cout << sum << std::endl;
	

	return 0;
}


int square (int number){
	return number * number;
}

int main(){
	std::cout << square(5) << std::endl; 

return 0;
}


int sumRange(int& from,int& to){
	int sum = 0;
	for (int i = from; i <= to;++i){
		sum += i;	
	}	
return sum;
}




int main(){
	int from = 0;
	int to = 0;
	std::cout << "input from and to :";
	std::cin >> from >> to;
	std::cout << sumRange(from,to) << std::endl;
	return 0;
}


void swap(int& a,int& b){
	int swap = a;
	a = b;
	b = swap;

	std::cout << a << b << std::endl;

}


int main(){
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	swap(a,b); 

return 0;
}

int multiply(int a, int b){
	return a * b;
}
double multiply(double a, double b){
	return a * b;
}


int main (){
	std::cout << multiply(5, 5) << std::endl;
	std::cout << multiply(5.0, 2.5) << std::endl;


return 0;
}

void printValue(int a){
	std::cout << a << std::endl;
}
void printValue(double a){
	std::cout << a << std::endl;
}
void printValue(std::string a){
	std::cout << a << std::endl;
}


int main(){
printValue(5);	
printValue(4.5);	
printValue("eric");	
return 0;
}




void multiply(int a, int b = 2){
	std::cout << a * b << std::endl;
}

inline int cube(int x){
	return x * x * x;
}

int main(){
multiply(5);
multiply(2,9);
std::cout << cube(3) << std::endl;


	return 0;
}


// Rrcursion____________________________

int sum(int n){
	if (n == 1){
		return 1;
	}
	return n + sum(n-1);  
}




int main(){
	std::cout << "res : " << sum(5) << std::endl;
	return 0;
}


int factorial(int f){
	if(f == 0){
		return 1;
	}if else(f < 0){
		std::cout << "f is negative" << std::endl;
		return 0;
	}else
		return f * factorial(f - 1);
}

int main (){
	int n = 0;
	std::cin >> n;
	std::cout << "resault : " << factorial(n) << std::endl;
	
	return 0;
}


//Factorial iteration____________________

int factorial(int n){
	if(n == 0){
		return 1;
	}
	if(n <= 0){
		std::cout << "n is negative" << std::endl;
		return 0;
	}
	int resault = 1;
	for(int i = 1;i <= n;++i){
		resault *= i;
	}
	
	return resault;

}

int main (){
	int n = 0;
	std::cin >> n;
	std::cout << "resault " << factorial(n) << std::endl;
	return 0;
}



//Array_________________________________________


int main(){
	int arr[5];
	for(int i = 0; i < 5;++i){
		std::cin >> arr[i];
	}
	int max = arr[0];
	for (int i = 0;i < 5;++i){
		if(arr[i] > max){
			max = arr[i];
		}
	}
	std::cout << max << std::endl;
	return 0;
}

//2d array)_________________________________



int main(){
	int arr[2][3];
	int sum = 0;
	for(int i = 0;i < 2;++i){
		for(int j = 0;j < 3;++j){
			std::cin >> arr[i][j];
			sum += arr[i][j];
		}	
	}
	std::cout << sum << std::endl;	

	
	return 0;
}


// Arrays and Functions

int sumArray(int arr[],int size){
	int sum = 0;
	for(int i = 0;i < size;++i){
		sum += arr[i];
	}
	return sum;
}

int main(){
	int arr[5];
	for(int i = 0;i < 5;++i){
		std::cin >> arr[i];
	}
	std::cout << sumArray(arr,5) << std::endl;

	return 0;
}


int findMax(const int arr[],const int size){
	int max = arr[0];
	for(int i = 0;i < size;++i){
		if(max < arr[i]){
			max = arr[i];
		}
	}
	return max;
}

int main(){
	int arr[5];
	for(int i = 0;i < 5;++i){
		std::cin >> arr[i];
	}
	std::cout << findMax(arr,5) << std::endl;

	return 0;
}

//pointer_________________________________________________

void swap (int* a ,int* b){
	int temp = *a;
       	*a = *b;
	*b = temp;
}

int main(){
	int a = 5;
	int b = 10;
	swap(&a,&b);
	std::cout << a << b << std::endl;
return 0;
}


void doubleElements(int* arr, int size) {
    for(int i = 0;i < size;++i){
    	arr[i] = 2 * arr[i]; 
    }
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    doubleElements(arr, 5);

    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}


//String_______________________________________________________________

#include <cstring>

int main() {
    char str1[] = "hello";
    char str2[] = "world";

    std::cout << "Длина str1: " << strlen(str1) << std::endl;

    char str3[20]; // обязательно достаточно места!
    strcpy(str3, str1); // копирует "hello" в str3
    std::cout << "str3 после копирования: " << str3 << std::endl;

    strcat(str3, str2); // добавляет "world" в конец "hello"
    std::cout << "str3 после конкатенации: " << str3 << std::endl;

    int result = strcmp(str1, str2); // сравнение
    std::cout << "Результат сравнения str1 и str2: " << result << std::endl;

    return 0;
}


int main(){
	std::string name = "Eric";
	std::cout << name.size() << std::endl;; 
	std::cout << name.length() << std::endl;; 
std::string text = "Hello world!";
std::cout << text[0];           // 'H'
std::cout << text.substr(6, 5); // "world"
std::cout << text.find("lo");   // 3
	return 0;
}

void squareAll(int* arr, int size){
	for(int i = 0; i < size;++i){
		arr[i] *= arr[i];

	}

}

int main(){
	int arr[5];	
	for (int i = 0;i < 5;++i){
		std::cin >> arr[i];
	
	}
	squareAll(arr,5);
	for (int i = 0;i < 5;++i){
		std::cout << arr[i] << std::endl;
	
	}

	return 0;
}


// DINAMIC memory / ptr to ptr




int main(){
	int sum = 0;
	int n = 0;
	std::cin >> n;
	int* arr = new int[n];
	for(int i = 0;i < n;++i){
		std::cin >> arr[i];
	}
	for(int i = 0;i < n;++i){
		std::cout << arr[i] << std::endl;
	}
	for(int i = 0;i < n;++i){
		sum += arr[i];
	}	
	std::cout << sum << std::endl;

	delete[] arr;	
	return 0;

}



int main(){
	int x = 0;
	int& ref = x;
	std::cin >> x;
	ref = 14;
	std::cout << x << std::endl;
	
	return 0; 
}

*/


//oop classs__________________________



class Car{
	public:
		void setMark(std::string mark){
			this->mark = mark; 
		} 
		std::string getMark() const{
			return this->mark;
		}
		void setYear(int year){
			this->year = year; 
		} 
		int getYear() const{
			return this->year;
		}
		
		Car() : mark(""),year(0){}
		Car(std::string mark,int year) : mark(mark), year(year){}
		~Car(){}
		
       		virtual void printinfo(){
			std::cout << this->mark << this->year << std::endl;
		}

	protected:
		std::string mark;
	 	int year;


};

class ElectricCar : public Car{

	public:
		void setBattery(int battery){
			this->battery = battery;
		}
		int getBattery() const{
			return this->battery;
		}
		
		ElectricCar(std::string mark,int year,int battery) : Car(mark,year), battery(battery) {}
		ElectricCar() : Car(), battery(0){} 
		~ElectricCar(){}
	
       		void printinfo() {
			std::cout << this->mark << this->year << this->battery << std::endl;
		}
	
	private:
		int battery;
};

int main(){
	Car c("bmw",2018);
	c.printinfo();
	ElectricCar e("mers",2005,10000);
	e.printinfo();

 Car* basePtr = new ElectricCar("Nissan", 2015, 6500);
    basePtr->printinfo(); // Выведет из ElectricCar
    delete basePtr;
	
	return 0;
}



