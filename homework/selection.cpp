#include <iostream>
#include <vector>

void swap(int& a,int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

void selection( std::vector<int>& arr ) {
	int size = arr.size();
	for( int i = 0; i < size; ++i ) { 
		int min = i;
		for( int j = i + 1; j < size; ++j ) {
			if( arr[min] > arr[j] ) {
			min = j;
			}
		}
		swap(arr[i],arr[min]);
	}
}

int main(){
	std::vector<int> vec = {10,9,5,4,6,8,1};	
	for(int x : vec){
		std::cout << x << " ";
	}
		std::cout << "\n";
	selection(vec);
	for(int x : vec){
		std::cout << x << " ";
	}
	return 0;
}
