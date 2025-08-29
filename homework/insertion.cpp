#include <iostream>
#include <vector>

void insertion(std::vector<int>& arr){
	int size = arr.size();
	for( int i = 1; i < size; ++i ) {
	 	int tmp = arr[i];
		int j = i - 1;
		while( j >= 0 && arr[j] > tmp ) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
	arr[j + 1] = tmp;
	}
}

int main(){
	std::vector<int> vec = {9,7,4,5,6,1};
	insertion(vec);
	for(int i : vec){
		std::cout << i << " ";
	}

	return 0;
}
