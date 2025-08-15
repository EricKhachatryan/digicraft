#include <iostream>
#include <string>

class LinkedListQueue {
//Constructors/destructors
public:
        LinkedListQueue() : size(0),topNode(nullptr) {}
        ~LinkedListQueue(){
                while(!isEmpty()){

                }
        }
//functions
public:
	void enqueue(int val){
       		Node* newNode = new Node(val);
		if(!isEmpty()){
			Node* tmp = topNode;
			while(tmp->next){
				tmp = tmp->next;
			}
			tmp->next = newNode;
		}else {
			topNode = newNode;

		}
		size++;
	}		
	void dequeue(){
		if(isEmpty()){
			std::cout << "Linked List is Empty" << std::endl;
			return;
		} else {
		Node* tmp = topNode->next;
	      	delete topNode;
		topNode = tmp;
		size--;
		}
	}
	int get(){return this->topNode->value;}	
      	int Size(){return this->size;}
      	bool isEmpty(){return this->topNode == nullptr;}
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
LinkedListQueue* link = new LinkedListQueue();
link->enqueue(5);
link->enqueue(4);
link->enqueue(3);
link->enqueue(1);
link->dequeue();
link->dequeue();
link->dequeue();
link->dequeue();
std::cout << link->get() << std::endl;
std::cout << link->Size() << std::endl;
	return 0;
}


