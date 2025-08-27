#include <iostream>

class Matrix{
public:
	Matrix(const int column,const int line) : pointer(nullptr), line(line), column(column){
		pointer = new int*[column];
		for(int i = 0 ; i < column;++i){
			pointer[i] = new int[line];
		}
		for (int i = 0;i < column;++i){
			for(int j = 0;j < line;++j){
				pointer[i][j] = 0;
			}
		}
	}
	
	~Matrix() {
        for (int i = 0; i < column; ++i) {
            delete[] pointer[i];
        }
        delete[] pointer;
	}
	
	Matrix(const Matrix& other) : column(other.column), line(other.line) {
        	pointer = new int*[column];
        	for (int i = 0; i < column; ++i) {
        	    pointer[i] = new int[line];
        	    for (int j = 0; j < line; ++j) {
        	        pointer[i][j] = other.pointer[i][j];
        	    }
        	}
    	}
//API
public:
	void setData(int c,int l,int n){
		if( l > 0 && l <= line && c > 0 && c <= column){
			pointer[c-1][l-1] = n;
		}
	}	
	
	int getData(int c , int l){
		if( l > 0 && l <= line && c > 0 && c <= column){
			return pointer[c-1][l-1];
		}
	}
	
	Matrix add(const Matrix& other){
		if (column == other.column || line == other.line) {
			Matrix res(column, line);
			for(int i = 0;i < column;++i){
				for(int j = 0 ; j < line;++j){
					res.pointer[i][j] = pointer[i][j] + other.pointer[i][j];
				}
			}
		return res;
		} else {
		return Matrix(column,line);
		}	
	
	}
	
	Matrix multiplay(const Matrix& other){
		if (column == other.column || line == other.line) {
			Matrix res(column, line);
			for(int i = 0;i < column;++i){
				for(int j = 0 ; j < line;++j){
					res.pointer[i][j] = pointer[i][j] * other.pointer[i][j];
				}
			}
		return res;
		} else {
		return Matrix(column,line);
		}	
	
	}
	
	void display(){
		for(int i = 0;i < column;++i){
			for(int j = 0 ; j < line;++j){
				if(j == 2){
					std::cout << pointer[i][j] << std::endl;
				} else {
				std::cout << pointer[i][j] << " ";
				}
			}
		}
		std::cout << "" << std::endl;
	}

private:
	int** pointer; 
	int line;
	int column;

};



int main(){
	Matrix* mx = new Matrix(3,3);
	Matrix* mx0 = new Matrix(3,3);
	
	
	mx->setData(1,1,50);
	mx->setData(1,2,60);
	mx->setData(1,3,80);
	mx->setData(2,1,90);
	mx->setData(2,2,100);
	mx->setData(2,3,15);
	mx->setData(3,1,30);
	mx->setData(3,2,40);
	mx->setData(3,3,60);
	
	
	mx0->setData(1,1,87);
	mx0->setData(1,2,45);
	mx0->setData(1,3,98);
	mx0->setData(2,1,96);
	mx0->setData(2,2,41);
	mx0->setData(2,3,97);
	mx0->setData(3,1,63);
	mx0->setData(3,2,74);
	mx0->setData(3,3,63);
	
	
	std::cout << mx->getData(3,1) << std::endl;
	std::cout << mx0->getData(3,1) << std::endl;
	

	mx->display();
	mx0->display();
	
	
	Matrix mx1 = mx->add(*mx0);
	mx1.display();
	
	
	Matrix mx2 = mx->multiplay(*mx0);
	mx2.display();


	return 0;
}
