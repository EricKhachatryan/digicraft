#include <iostream>
#include <string>
#include <vector>


class Book {

	//constructor/destructor
	public:
    		Book() : id(0), title(""), author(""), genre(""), totalCopies(0), availableCopies(0) {}
		Book(int id, const std::string t, const std::string a, const std::string g, int tcopies, int acopies)
      		: id(id), title(t), author(a), genre(g), totalCopies(tcopies), availableCopies(acopies) {}
    		~Book(){}
		int getID() const { return id; }
    		std::string getTitle() const { return title; }

	//functions	
	public:
		 void addBook() {
        		std::cout << "Input Book ID : ";
        		std::cin >> id;
        		std::cin.ignore();
        		std::cout << "Input Book Name : ";
        		std::getline(std::cin, title);

        		std::cout << "Input Book Author : ";
        		std::getline(std::cin, author);

        		std::cout << "Input Book Genre : ";
     			std::getline(std::cin, genre);

        		std::cout << "Input Book TotalCopies: ";
        		std::cin >> totalCopies;
        		availableCopies = totalCopies;    
		}

		void showBook() const {
        		std::cout << "ID: " << id
                	<< " | Name: " << title
                	<< " | Author: " << author
                	<< " | Genre: " << genre
                	<< " | TotalCopies: " << totalCopies
               		<< " | AvailableCopies: " << availableCopies
                  	<< std::endl;
		}

		void borrowBook() {
        		if (availableCopies > 0) {
        		availableCopies--;
            		std::cout << "Book '" << title << "'successfully taken" << std::endl;
        		} else {
            		std::cout << "Book '" << title << "' Not available for pickup." << std::endl;
			}	
    		}

		void returnBook() {
        		if (availableCopies < totalCopies) {
            		availableCopies++;
            		std::cout << "Book '" << title << "' uccessfully returned" << std::endl;
        		} else {
            		std::cout << "All Book Copies'" << title << "' already on site." << std::endl;
        		}
    		}
	
		int getID(){ return this->id; }

    		std::string getTitle(){ return this->title; }
		

	//members data
	private:
		int id;
		std::string title;
		std::string author;
		std::string genre;
    		int totalCopies;
    		int availableCopies;

};

class User {
	private:
    		std::string username;
    		std::string password;
    		std::vector<int> borrowedBookIDs; // хранит ID взятых книг (максимум 3)

	public:
    	// Регистрация пользователя
    		void registerUser() {
    			username = "eric";
			password = "pass";
		}

    		// Вход в систему
    		bool login(const std::string& uname, const std::string& pass) {
        		return (uname == username && pass == password);
    		}

    		// Взять книгу
    		void borrowBook(std::vector<Book>& books) {
        		if (borrowedBookIDs.size() >= 3) {
        	    		std::cout << "You have taken the maximum number of books (3)" << std::endl;
            			return;
        		}
		
        		int id;
        		std::cout << "Input Book ID: ";
        		std::cin >> id;

        		for (auto& book : books) {
            			if (book.getID() == id) {
                			book.borrowBook();
                			borrowedBookIDs.push_back(id);
                			return;
            			}
        		}
        		std::cout << "Book with this ID not found" << std::endl;
   		}

    		// Вернуть книгу
    		void returnBook(std::vector<Book>& books) {
        		if (borrowedBookIDs.empty()) {
            			std::cout << "You didn't take the books" << std::endl;
            			return;
        		}

        		int id;
        		std::cout << "Input Book ID: ";
        		std::cin >> id;

        		for (auto it = borrowedBookIDs.begin(); it != borrowedBookIDs.end(); ++it) {
            			if (*it == id) {
                			for (auto& book : books) {
                    				if (book.getID() == id) {
                        				book.returnBook();
                        				borrowedBookIDs.erase(it);
                        				return;
                    				}
                				}
            			}
        		}
        		std::cout << "you didn't take the book from that id" << std::endl;
   		}

    		// Показать все взятые книги
    		void viewBorrowedBooks(const std::vector<Book>& books) const {
        		if (borrowedBookIDs.empty()) {
            			std::cout << "No books taken." << std::endl;
            			return;
        		}

        		std::cout << "Your borrowed books:" << std::endl;
        		for (int id : borrowedBookIDs) {
            			for (const auto& book : books) {
                			if (book.getID() == id) {
                    			book.showBook();
                			}
            			}
        		}
   	 		}
};
class Admin {
	public:
		void addBook(std::vector<Book>& books) {
        		Book newBook;
        		newBook.addBook(); // Request book data input
        		books.push_back(newBook);
        		std::cout << "Book successfully added!" << std::endl;
    		}

    		void removeBook(std::vector<Book>& books) {
        		if (books.empty()) {
            			std::cout << "No books to remove." << std::endl;
            			return;
        		}

        		int id;
        		std::cout << "Enter book ID to remove: ";
        		std::cin >> id;

        		for (auto it = books.begin(); it != books.end(); ++it) {
            			if (it->getID() == id) {
                			books.erase(it);
                			std::cout << "Book removed." << std::endl;
                			return;
            			}
        		}
        		std::cout << "Book with this ID not found." << std::endl;
   		}

    		void viewAllBooks(const std::vector<Book>& books) {
        		if (books.empty()) {
            			std::cout << "No books in the library.\n";
            			return;
        		}
        		std::cout << "\n=== List of all books ===\n";
        		for (const auto& book : books) {
            			book.showBook();
        		}
    		}

    		void viewUsers(const std::vector<User>& users) {
        		if (users.empty()) {
            			std::cout << "No users registered.\n";
            			return;
        		}
        		std::cout << "\n=== List of users ===\n";
        		for (size_t i = 0; i < users.size(); ++i) {
            			std::cout << i + 1 << ". User registered.\n"; 
            			// Optionally, output user name via getter
        		}
    		}
};

int main(){

Book b(50,"eric","eric","eric",10,20);
std::cout << b.getID() << std::endl;
std::cout << b.getTitle() << std::endl;



	return 0;
}
