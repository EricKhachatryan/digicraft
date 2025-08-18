#include <iostream>
#include <string>

class Tree{
struct Node;
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
		if(node == nullptr){
		} else {
			std::cout << node->value << std::endl;
			showPreInner(node->left);
			showPreInner(node->right);
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
tree->preOrder();
return 0;
}
