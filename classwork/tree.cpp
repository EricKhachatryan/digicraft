#include <iostream>
#include <string>

class Tree{
//public API
public:
	bool visEmpty(){return this->root->!value;}
	
	void insert(int val){
		insertInner();		
	
	}
	

// helper fun
private:
	Node* insertInner(Node* node, int val){
	
	}

// struct Node
private:
	struct Node{
	public:
		Node(int val) : value(val), left(nullptr), right(nullptr) {}
		int value;
		Node* left;
		Node* right;
	};
//data members
private:
	Node* root;	


};

int main (){
Tree* tree = new Tree();
tree->insert(20);
tree->insert(10);
tree->insert(60);
tree->insert(90);
return 0;
}
