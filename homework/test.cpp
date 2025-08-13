#include <iostream>
#include <string>

class MyVector{
	public:
		MyVector() : size(0), capacity(0), arr(nullptr){}
		~MyVector(){
			delete[] arr;
		}
		void push_back(int num){
			if(size == capacity){
			resize(capacity == 0 ? 1 : capacity * 2);
			}
			arr[size++] = num;
		}
		void pop_back(){
			if(size > 0){	
				size--;
			}
		}
		int Size(){return this->size;}
		int Capacity(){return this->capacity;}
		void clear(){
			size = 0; 
		}
		void at(int num){
			std::cout << arr[--num] << std::endl;
		}
	private:
		void resize(int cap){
			int* newarr = new int[cap];
			for(int i = 0; i < size ; i++){
				newarr[i] = arr[i];
			}
			delete[] arr;	
			arr = newarr;
			capacity = cap;	
			}
	private:
		int size;
		int capacity;
		int* arr;

};



int main(){
	MyVector vec;
	vec.push_back(5);	
	std::cout << vec.Size() << std::endl;
	std::cout << vec.Capacity() << std::endl;
	vec.push_back(510);	
	std::cout << vec.Size() << std::endl;
	std::cout << vec.Capacity() << std::endl;
	vec.push_back(6856);	
	std::cout << vec.Size() << std::endl;
	std::cout << vec.Capacity() << std::endl;
	vec.at(1);	
	vec.pop_back();
	std::cout << vec.Size() << std::endl;
	std::cout << vec.Capacity() << std::endl;
	vec.clear();
	std::cout << vec.Size() << std::endl;
	std::cout << vec.Capacity() << std::endl;
	return 0;
}
