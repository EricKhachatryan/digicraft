#include <iostream>

class MyInt{
public:
	MyInt(){}
	MyInt(int val): val(val){}
	MyInt(const MyInt& other){
	this->val = other.val; 
	}
	~MyInt(){}

	MyInt operator+ (const MyInt& other){
	MyInt ret;
	ret.val = val + other.val;
	return ret;
	}
	
	MyInt operator- (const MyInt& other){
	MyInt ret;
	ret.val = val - other.val;
	return ret;
	}

	MyInt operator* (const MyInt& other){
	MyInt ret;
	ret.val = val * other.val;
	return ret;
	}

	MyInt operator/ (const MyInt& other){
	MyInt ret;
	ret.val = val / other.val;
	return ret;
	}
	
	bool operator> (const MyInt& other){
	bool bo = false;
		if( val > other.val){
			bo = true;
		}
			return bo;
	}

	bool operator< (const MyInt& other){
	bool bo = false;
		if( val < other.val){
			bo = true;
		}
			return bo;
	}

	bool operator!= (const MyInt& other){
	bool bo = false;
		if( val != other.val){
			return bo;
		}else
			bo = true;	
			return bo;
	}

	
	MyInt& operator= (const MyInt& other){
	this->val = other.val;
	return *this;
	}





private:
	int val;



};






int main(){
	MyInt my;
	MyInt my1;
	MyInt my2;
	my.val = 10;
	my1 = my2;
	if (my1 < my2);
	if (my1 > my2);
	bool ret = my1 != my2;
	return 0;
}
