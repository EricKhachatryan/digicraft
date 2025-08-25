#include <iostream>

class Havasarum{	
//API
public:
	
	void insert(int pref, int exp){
		if( pref == 0 ) { return;}
		Node* newNode = new Node(pref,exp);
		newNode->next = head;
		head = newNode;	
	}	
	
	void display(){
		if( head == nullptr){
			std::cout << 0 << std::endl;
			return;
		}
		Node* curr = head;
		while( curr != nullptr ){
			std::cout << curr->pref << "x^" << curr->exp;
			if(curr->next != nullptr){
				std::cout << " + ";
			}
			curr = curr->next;
		}
		std::cout << "\n";
	}
	
	int evaluate(int value){
		if( head == nullptr ){
			return 0;
		}
		int sum = 0;
		Node* curr = head;
		while( curr != nullptr ){
			sum += curr->pref * exponent(value, curr->exp);
			curr = curr->next;
		}
		return sum;
	}
	 Havasarum* add(const Havasarum& other) {
	        Havasarum* result = new Havasarum();
		Node* curr1 = head;
	        Node* curr2 = other.head;
	        
		while (curr1 != nullptr && curr2 != nullptr) {
	            if (curr1->exp == curr2->exp) {
	                int newPref = curr1->pref + curr2->pref;
	                if (newPref != 0) {
	                    result->insert(newPref, curr1->exp);
	                }
	                curr1 = curr1->next;
	                curr2 = curr2->next;
	            }
	            else if (curr1->exp > curr2->exp) {
	                result->insert(curr1->pref, curr1->exp);
	                curr1 = curr1->next;
	            }
	            else {
	                result->insert(curr2->pref, curr2->exp);
	                curr2 = curr2->next;
	            }
	        }
	        
	        while (curr1 != nullptr) {
	            result->insert(curr1->pref, curr1->exp);
	            curr1 = curr1->next;
	        }
	        
		while (curr2 != nullptr) {
	            result->insert(curr2->pref, curr2->exp);
	            curr2 = curr2->next;
	        }
	        
	        return result;
	    }

//Helper functions
private:
	int exponent(int base,int exp){
		if(exp == 0) {return 1;}
		int sum = 1;
		for(int i = 0; i < exp;i++){
			sum += base;
		}
		return sum;
	}
	

// members data
private:
	struct Node{
		Node(int extExp,int extPref) : 
			next(nullptr),
			pref(extPref),
			exp(extExp) { }
		~Node() {}
		Node* next;
		int exp;
		int pref;
	};

	Node* head;

};



int main() {
    Havasarum* poly1 = new Havasarum();
    Havasarum* poly2 = new Havasarum();
    
    poly1->insert(8, 7);
    poly1->insert(8, 7);
    poly1->insert(8, 7);
    poly1->insert(8, 7);
    poly1->insert(8, 7);
    poly1->insert(8, 7);
    
    poly2->insert(5, 7);
    poly2->insert(3, 5);
    
    std::cout << "First polynomial: ";
    poly1->display();
    std::cout << "Second polynomial: ";
    poly2->display();
    
    Havasarum* sum = poly1->add(*poly2);
    std::cout << "Sum: ";
    sum->display();
    
    std::cout << "Evaluate sum at x=9: " << sum->evaluate(9) << std::endl;
    
    delete poly1;
    delete poly2;
    delete sum;
    
    return 0;
}
