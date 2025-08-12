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
    		std::vector<int> borrowedBookIDs; 
	public:
    		void registerUser() {
    			username = "eric";
			password = "pass";
		}

    		bool login(const std::string& uname, const std::string& pass) {
        		return (uname == username && pass == password);
    		}

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
        		newBook.addBook();
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
                        }
                }
};

void userMenu(User& user, std::vector<Book>& books){
	int input = 0;
	while (true) {
		std::cout << "=======USER-MENU=======" << std::endl;
		std::cout << "Borrow book = press 1" << std::endl;
		std::cout << "Return book = press 2" << std::endl;
		std::cout << "View borrowed books = press 3" << std::endl;
		std::cout << "View all books = press 4" << std::endl;
		std::cout << "Logout = press 5" << std::endl;
		std::cout << "input number : ";
		std::cin >> input;		
		switch(input){
			
			case 1:{
				user.borrowBook(books);
				break;
			       }
			case 2:{
				user.returnBook(books);       
				break;
			       }
			case 3:{
				user.viewBorrowedBooks(books);
				break;
			       }
			case 4:{
				std::cout << user.viewAllBooks() << std::endl;
				break;
			       }
			case 5:{
				std::cout << "you Logout!" << std::endl;
				return;
			       }
			default:{
				std::cout << "you input incorrect number input 1,2,3,4 or 5!" << std::endl;
				break;
				}
		}
	}
}



void adminMenu(Admin& admin,std::vector<Book>& books,User& user){
	int input = 0;
	while (true) {
		std::cout << "=======ADMIN-MENU=======" << std::endl;
		std::cout << "Add book = press 1" << std::endl;
		std::cout << "Remove book = press 2" << std::endl;
		std::cout << "View all books = press 3" << std::endl;
		std::cout << "View Users = press 4" << std::endl;
		std::cout << "Logout = press 5" << std::endl;
		std::cout << "input number : ";
		std::cin >> input;		
		switch(input){
			case 1:{
				admin.addBook(books);       
				break;
			       }
			case 2:{
				admin.removeBook(books);
				break;
			       }
			case 3:{
				admin.viewAllBooks(books);
			 	break;
			       }
			case 4:{
				       std::vector<User> tmpUser = {user}; 
				admin.viewUsers(tmpUser);
				break;
			       }
			case 5:{
				std::cout << "you Logout!" << std::endl;
				return;
				}
			default:{
				std::cout << "you input incorrect number input 1,2,3,4 or 5!" << std::endl;
				break;
				}
		}
	}
}


void loginMenu(std::vector<Book>& books,User& user){
	Admin admin;
	int input = 0;
	while (true) {
		
		std::cout << "=======MENU=======" << std::endl;
		std::cout << "Login as Admin = Press 1" << std::endl;
		std::cout << "Login as User = Press 2" << std::endl;
		std::cout << "Exit = Press 3" << std::endl;
		std::cout << "Input number : ";
		std::cin >> input;
		switch(input){
			case 1: {
				for ( int i = 0 ; i < 3; ++i ){
					std::string login,password;
					std::cout << "=======ADMIN=======" << std::endl; 
					std::cout << "Login : "; 
					std::cin >> login;
					std::cout << "Password : "; 
					std::cin >> password;
					if( login == "eric" && password == "pass" ){
						std::cout << "you have successfully logged in as admin!" << std::endl;
						adminMenu(admin,books,user);
						break;
					}else{
						std::cout << "password or login incorrect" << std::endl;
					}
				}
				break;
				}
			case 2:{
				user.registerUser();
				for ( int i = 0 ; i < 3; ++i ){
					std::string login,password;
					std::cout << "=======USER=======" << std::endl; 
					std::cout << "Login = "; 
					std::cin >> login;
					std::cout << "Password = "; 
					std::cin >> password;
					if(user.login(login,password)){
						std::cout << "you have successfully logged in as user!" << std::endl;
						userMenu(user,books);
						break;
					}else{
						std::cout << "password or login incorrect" << std::endl;
					}
				}
				break;
			       }
			case 3:{
				std::cout << "Goodbye" << std::endl;	
				return;
			       }
			default:{
				std::cout << "you input incorrect number input 1,2 or 3!" << std::endl;
				break;
				}
		}
	}	
} 


int main(){

std::vector<Book> books;
User user;
loginMenu(books,user);






	return 0;
}
