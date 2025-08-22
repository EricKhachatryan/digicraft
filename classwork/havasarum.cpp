#include <iostream>
#include <string>

class Linkedlist{
//Constructors/Destructors
public: 
	Linkedlist() : head(nullptr) {}
	~Linkedlist(){
		while(head != nullptr){
		Node* tmp = head-next;
			delete head;
		}
	}
//publicv API
public:
	void insert( int exp, int b ){
		if(pref == 0){return;}
		Node* newnode = new Node(a,b);
	}
// Node
private:
	struct Node{
		public:
			Node(int p,int e) : next(nullptr),pref(p),exp(e) {}
			Node* next;
			int exp;
			int pref;
	};
// members data
private:
	Node* head;
};









int main(){
Linkedlist link = new Linkedlist();
link->insert(8,7);
link->insert(8,7);
link->insert(8,7);
link->insert(8,7);
link->insert(8,7);
link->insert(8,7);
link->display();
link->evaluate(9);
	return 0;

}
