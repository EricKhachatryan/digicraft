#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

/*
void threadHello(std::string name){
	std::cout << "hello" << name << std::endl;
}

int main(){
	std::thread t(threadHello,"kim");
	std::cout << "hello from Main thread" <<std::endl;
	t.join();
	return 0;
}

std::mutex mtx;
int counter = 0;

int increment(int a){
	std::lock_guard<mutex> lock(mtx);
	a++;
	std::cout << a << std::endl;
	counter++;
	return a;
}


int main(){
	std::thread t1(increment,10);
	std::thread t2(increment,20);
	t1.detach();
	t2.detach();
	mtx.lock();
	std::cout << counter << std::endl;
	mtx.unlock();
	return 0;
}

*/

std::mutex mtx;
std::condition_variable cv;
std::queue<int> container;
int size = 5;

void producer(){
	for(int i=0;i < 10;i++){
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock,[]{return container.size() < size;});
		std::cout << "adding" << i << std::endl;
		container.push(i);	
		cv.notify_all();
	}

}

void consumer(){
	for(int i=0;i < 10;i++){
		std::unique_lock<std::mutex> lock(mtx);
		cv.wait(lock,[]{return !container.empty();});
		container.pop();	
		std::cout << "consuming" << std::endl;
		cv.notify_all();
	}

}


int main(){
	std::thread t1(producer);
	std::thread t2(consumer);
	t1.join();
	t2.join();
	return 0;
}
