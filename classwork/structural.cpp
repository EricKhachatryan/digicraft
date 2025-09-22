#include <iostream>
#include <string>
#include <memory>


// adapter_______________________

/*

class Player{
public:
	virtual void play(std::string song) = 0;

};

class mp3Player{
public:
	void playmp3(std::string song) {
		std::cout << "playmp3: " << song << std::endl;
	}

};

class PlayerAdapter : public Player{
private:
	mp3Player player;
public:
	void play(std::string song) override {
		player.playmp3(song);
	}
};

int main(){
Player* p = new PlayerAdapter();
p->play("MyfevoritSong.mp3");

return 0;
}
*/

// Decorator 


class Coffee {
public:
	virtual std::string description() = 0;
	virtual int cost() = 0;

};

class SimpleCoffee : public Coffee {
public:
	virtual std::string description() override {
		return "Simple Coffee";
	}
	
	virtual int cost() override {return 600;}
};

class CoffeeDecorator : public Coffee {
protected:
	std::unique_ptr<Coffee> coffee;
public:	
	CoffeeDecorator(std::unique_ptr<Coffee> type) : coffee(std::move(type)) {};
};

class Milk : public CoffeeDecorator {
public:
	Milk(std::unique_ptr<Coffee> type) : CoffeeDecorator(std::move(type)) {};
	virtual std::string description() override {
		return coffee->description() + " + milk";
	}
	virtual int cost() override {
		return coffee->cost() + 200;
	}

};

class Sugar : public CoffeeDecorator {
public:
	Sugar(std::unique_ptr<Coffee> type) : CoffeeDecorator(std::move(type)) {};
	virtual std::string description() override {
		return coffee->description() + " + sugar";
	}
	virtual int cost() override {
		return coffee->cost() + 200;
	}

};


int main() {
std::unique_ptr<Coffee> coffee1 = std::make_unique<SimpleCoffee>();
coffee1 = std::make_unique<Milk>(std::move(coffee1));
coffee1 = std::make_unique<Sugar>(std::move(coffee1));
std::cout << coffee1->description() << std::endl;
std::cout << coffee1->cost() << std::endl;


return 0;
}

































