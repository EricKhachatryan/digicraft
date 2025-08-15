#include <iostream> 
#include <string>

class LinkedListStack {
	//Constructors/destructors	
	public:
		LinkedListStack() : size(0),topNode(nullptr) {}	
		~LinkedListStack(){
			while(!isEmpty()){
				pop_back();
			}
		}	   	
	//functions
	public:
		void push_back(int val){
			Node* newNode = new Node(val);
			newNode->next = topNode;
			topNode = newNode;
			size++;
		}
		void pop_back(){
			Node* tmp = topNode;
			topNode = topNode->next;
			delete tmp;
			size--;
		}
		int get(){return this->topNode->value;}
		
		int Size(){return this->size;}
		
		int isEmpty(){return this->topNode == nullptr;}
	 	 //node struct
	private:
		struct Node{
			public:
				Node(int val) : value( val ),next(nullptr) {}
				int value;
				Node* next;
		};
	//members data
	private:
		Node* topNode;
		int size;
};

int main(){
LinkedListStack* link = new LinkedListStack();
link->push_back(7);
link->push_back(8);
link->push_back(1);
link->push_back(3);
link->pop_back();
std::cout << link->get() << std::endl;	
std::cout << link->Size() << std::endl;	
return 0;
}

