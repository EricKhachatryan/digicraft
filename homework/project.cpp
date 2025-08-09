#include <iostream>
#include <string>
#include <vector>


class Book {

	public:
    		Book() : id(0), title(""), author(""), genre(""), totalCopies(0), availableCopies(0) {}
		Book(int id, const std::string t, const std::string a, const std::string g, int tcopies, int acopies)
      		: id(id), title(t), author(a), genre(g), totalCopies(tcopies), availableCopies(acopies) {}
    		~Book(){}
		int getID() const { return id; }
    		std::string getTitle() const { return title; }

	private:
		int id;
		std::string title;
		std::string author;
		std::string genre;
    		int totalCopies;
    		int availableCopies;

};





int main(){

Book b(50,"eric","eric","eric",10,20);
std::cout << b.getID() << std::endl;
std::cout << b.getTitle() << std::endl;



	return 0;
}
