#include <iostream>

class Fraction(){
public:
	Fraction() : up(0), down(0){}
	Fraction(int up,int down) : up(up), down(down) {
	
	}
	~Fraction(){}
public:
	Fraction* add(const Fraction& extFract ){
	gcd(this->down,extFract->down);
	
	
	}	

	int GCD(int this->down,int extFract->down){
		int 
	}


private:
	int up;
	int down;

};






int main(){
Fraction* fr1 = new Fraction(1,2);
Fraction* fr2 = new Fraction(2,4);
fr1.add(fr2);
return 0;
}
