#include <iostream>

class Fraction {
public:
    Fraction() : num(0), denum(1) {}

    Fraction(int n, int d) {
        if (d == 0) {
            std::cout << "denum can't be 0 " << std::endl;
            num = 0;
            denum = 1;
            return;
        }
        int g = gcd(n, d); 
        num = n / g;       
        denum = d / g;     
        if (denum < 0) {   
            num = -num;
            denum = -denum;
        }
    }

    ~Fraction() {
    }

    Fraction addConst(Fraction extFract) {
        int newDenum = denum * extFract.denum;
        int newNum = num * extFract.denum + denum * extFract.num;
        int gcdValue = gcd(newNum, newDenum); 
        return Fraction(newNum / gcdValue, newDenum / gcdValue); 
    }

    void print() const {
        std::cout << num << "/" << denum << std::endl;
    }

private:
    int num;
    int denum;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a < 0 ? -a : a; 
    }
};

int main() {
    Fraction* fr1 = new Fraction(1, 2); 
    Fraction* fr2 = new Fraction(2, 4); 
    Fraction result = fr1->addConst(*fr2); 
    std::cout << "Result: ";
    result.print(); 
    delete fr1; 
    delete fr2; 
    return 0;

}
