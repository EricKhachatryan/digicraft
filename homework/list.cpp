#include <iostream> 
#include <string>

class LinkedList {
	//Constructors/destructors	
	public:
		LinkedList() : head(nullptr), size(0) {}	
		~LinkedList(){
			while(head){
				Node* tmp = head;
				head = head->next;
				delete tmp;
			}
		}	   	
	//functions
	public:
		void push_back(int val){
			Node* newNode = new Node(val);
			if(!head){
				head = newNode;
			}else {
				Node* curr = head;
				while(curr->next){
					curr = curr->next;
				}
				curr->next = newNode;
				}
			size++;
		}
		void pop_back(){
			if(!head){
				return;
			}																																			
			if(!head->next){
				delete head;
				head = nullptr;
			}else	{
				Node* curr = head;
				while(curr->next){
					curr = curr->next;
				}
				delete curr->next;
				curr->next = nullptr;
			}
			size--;

		}
		int getSize(){return this->size;}
	
		 int at(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;;
            return -1; 
		}
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }
		
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
		Node* head;
		int size;
};

int main(){
LinkedList* link = new LinkedList();
link->push_back(7);
link->push_back(7);
link->push_back(7);
link->push_back(7);
link->push_back(7);
std::cout << link->getSize() << std::endl;
link->pop_back();
std::cout << link->getSize() << std::endl;
link->pop_back();
link->pop_back();
link->pop_back();
link->pop_back();
std::cout << link->getSize() << std::endl;
	return 0;
}
