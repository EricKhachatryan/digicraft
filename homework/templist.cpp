#include <iostream> 
#include <string>


template<typename T>
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
		void push_back(T val){
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
	
		 T at(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;; 
	    	return T();
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
				Node(T val) : value( val ),next(nullptr) {}
				T value;
				Node* next;
		};
	//members data
	private:
		Node* head;
		int size;
};

int main(){
LinkedList<std::string> link;
link.push_back("Eric");
link.push_back("E");
link.push_back("K");
link.push_back("E");
link.push_back("a");
std::cout << link.getSize() << std::endl;
link.pop_back();
std::cout << link.getSize() << std::endl;
std::cout << link.getSize() << std::endl;
std::cout << link.at(0) << std::endl;
std::cout << link.at(1) << std::endl;
std::cout << link.at(2) << std::endl;
std::cout << link.at(3) << std::endl;
std::cout << link.at(4) << std::endl;
return 0;
}
