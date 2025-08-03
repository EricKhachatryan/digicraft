#include <iostream>
#include <string>

class MyVector{
        public:
                void push_back(int num){
                        if( size == capacity ){
				resize( capacity == 0 ? 1 : capacity * 2 );
		}
			arr[size++] = num;
		}
     		void pop_back(){
			if( size > 0 ){
				size--;
			}
		}
		void clear(){
			size = 0;
		}
		int Size(){return this->size;}
	       	int Capacity(){return this->capacity;}
		

        public:
                MyVector() : size(0), capacity(0), arr(nullptr) {}
                ~MyVector(){
			delete[] arr;
		}
        //private functions
	private:
		void resize(int newcap){
			int* newarr = new int[newcap];
			for( int i = 0;i < size; i++ ){
				newarr[i] = arr[i];
			}
			delete[] arr;
			arr = newarr;
			capacity = newcap;
		}
	
	//private members
	private:
                int size;
                int capacity;
                int* arr;
};


int main(){
        MyVector* vector = new MyVector();
        vector->push_back(50);
	std::cout << vector->Size() << std::endl;
	std::cout << vector->Capacity() << std::endl;
        vector->push_back(50);
	std::cout << vector->Size() << std::endl;
	std::cout << vector->Capacity() << std::endl;
	vector->pop_back();
	std::cout << vector->Size() << std::endl;
	std::cout << vector->Capacity() << std::endl;
	vector->clear();
	std::cout << vector->Size() << std::endl;
	std::cout << vector->Capacity() << std::endl;
	return 0;

}

