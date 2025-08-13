#include <iostream> 
#include <string>

class LinkedList {
	//Constructors/destructors	
	public:
		LinkedList() : size(0),topNode(nullptr) {}	
		~LinkedList(){
			while(topNode){
				Node* tmp = topNode;
				topNode = topNode->next;
				delete tmp;
			}
		}	   	
	//functions
	public:
		void push_back(int val){
			Node* newNode = new Node(val);
			if(!topNode){
				topNode = newNode;
			}else {
				Node* curr = topNode;
				while(curr->next){
					curr = curr->next;
				}
				curr->next = newNode;
				topNode = newNode;
				}
			size++;
		}
		void pop_back(){
			if(!topNode){
				return;
			}														
			if(!topNode->next){
				delete topNode;
				topNode = nullptr;
			}else	{
				Node* curr = topNode;
				while(curr->next){
					curr = curr->next;
				}
				delete curr->next;
				curr->next = nullptr;
				topNode = curr;
			}
			size--;
		}
		int getSize(){return this->size;}
	
	int gettopNode(){return this->topNode->value;}
	
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
LinkedList* link = new LinkedList();
link->push_back(7);
link->push_back(8);
link->push_back(1);
link->push_back(3);
link->pop_back();
std::cout << link->gettopNode() << std::endl;	
return 0;
}

