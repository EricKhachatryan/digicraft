#include <iostream>
#include <string>

class Tree{
struct Node;
//Constructor/destructor
public:
	Tree(): root(nullptr) {}
	~Tree(){
		Delete(root);	
	}	


//public API
public:
	void insert(int val){
		root = insertInner(root, val);		
	}
 	void preOrder(){
		showPreInner(root);
	}
	void postOrder(){
		showPostInner(root);
	}
	void inOrder(){
		showInInner(root);
	}
	Node* search(int val){
		return searchValue(root,val);
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
// helper functions 
private:
	void showPreInner(Node* node){
		if(node == nullptr){return;}
		std::cout << node->value << std::endl;
		showPreInner(node->left);
		showPreInner(node->right);
		
	}	

	void showPostInner(Node* node){
		if(node == nullptr){return;}
		showPostInner(node->left);
		showPostInner(node->right);
		std::cout << node->value << std::endl;
		
	}	


	void showInInner(Node* node){
		if(node == nullptr){return;}
		showPostInner(node->left);
		std::cout << node->value << std::endl;
		showPostInner(node->right);

	}
	
	Node* searchValue(Node* node,int val){
		if( node == nullptr || node->value == val){return node;}
		if(val < node->value){
			return searchValue( node->left, val );
		} else {
			return searchValue( node->right, val );
		}
		
	}

	Node* insertInner(Node* node, int val){
		if(node == nullptr){
			return new Node(val);
		}
		if(val < node->value){
			node->left = insertInner(node->left,val);
		} else {
			node->right = insertInner(node->right,val);
		}
		return node;
	
	}
	
	void Delete(Node* node){
		if(node == nullptr){return;}
		Delete(node->left);
		Delete(node->right);
		delete node;

	}	
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
tree->insert(30);
tree->insert(40);
tree->insert(50);
tree->insert(80);
tree->insert(18);
tree->insert(16);
tree->insert(38);
tree->insert(75);
tree->insert(1);
tree->postOrder();
tree->search(50);
return 0;
}
