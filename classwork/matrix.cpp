#include <iostream>

class Matrix{
public:
	Matrix(const int column,const int line) : pointer(nullptr), line(line), column(column){
		pointer = new int*[column];
		for(int i = 0 ; i < column;++i){
			pointer[i] = new int[line];
		}
	}
//API
public:
	void setData(int c,int l,int n){
		if( l > 0 && l < line && c > 0 && c < column){
			pointer[c][l] = n;
		}
	}	
	
	int getData(int c , int l){
		if( l > 0 && l < line && c > 0 && c < column){
			return pointer[c][l];
		}
	}
	
	Matrix add(const Matrix& other){
		Matrix res(column, row);
		for(int i = 0;i < column;++i){
			for(int j = 0 ; j < line;++j){
				res.pointer[i][j] = pointer[i]{j} + other.pointer[i][j];
			}
		}
	return res;
	}
       	

private:
	int** pointer; 
	int line;
	int column;

};



int main(){
	Matrix* mx = new Matrix(3,3);
	mx->setData(3,2,7);
	mx->getData(3,2);
	Matrix mx1 = mx->add(mx0);
	return 0;
}
