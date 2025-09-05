#include <iostream>
#include <string>

template <typename T>
class MyVector{
        public:
                void push_back(const T& num){
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
		
		void at(int num){
			std::cout << arr[--num] << std::endl;	
		}	

        public:
                MyVector() : size(0), capacity(0), arr(nullptr) {}
                ~MyVector(){
			delete[] arr;
		}
        //private functions
	private:
		void resize(int newcap){
			T* newarr = new T[newcap];
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
                T* arr;
};


int main(){
	MyVector<std::string> v;	
        v.push_back("Eric");
	std::cout << v.Size() << std::endl;
	std::cout << v.Capacity() << std::endl;
        v.push_back("Khachatryan");
	std::cout << v.Size() << std::endl;
	std::cout << v.Capacity() << std::endl;
	v.at(1);
	v.at(2);
	std::cout << v.Size() << std::endl;
	std::cout << v.Capacity() << std::endl;
	return 0;

}

