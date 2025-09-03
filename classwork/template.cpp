#include <iostream>

template <typename T>
class Temp {
	public:
		T lval;
		T rval;
		
		Temp(T a,T b) : lval(a), rval(b) {
		}
		~Temp(){};

			
		T Min(T lval, T rval){
			if(lval < rval ){
				return lval;
			}else
				return rval;
		}

		T Max(T lval, T rval){
			if(lval < rval ){
				return rval;
			}else
				return lval;
		}

};


int main(){


}
