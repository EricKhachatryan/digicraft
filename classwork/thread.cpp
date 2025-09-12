#include <iostream>
#include <thread>
#include <string>

void threadHello(std::string name){
	std::cout << "hello" << name << std::endl;
}

int main(){
	std::thread t(threadHello,"kim");
	std::cout << "hello from Main thread" <<std::endl;
	t.join();
	return 0;
}
