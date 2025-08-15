#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Person {
protected:
    std::string username;
    std::string password;
public:
    virtual bool login(const std::string& uname, const std::string& pass) = 0;
    virtual ~Person() {}
    std::string getUsername() const { return username; }
};

class Book {
public:
    Book() : id(0), title(""), author(""), genre(""), totalCopies(0), availableCopies(0), borrowCount(0) {}
    Book(int id, const std::string& t, const std::string& a, const std::string& g, int tcopies, int acopies, int bcount = 0)
        : id(id), title(t), author(a), genre(g), totalCopies(tcopies), availableCopies(acopies), borrowCount(bcount) {}
    ~Book() {}

    int getID() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getGenre() const { return genre; }
    int getTotalCopies() const { return totalCopies; }
    int getAvailableCopies() const { return availableCopies; }
    int getBorrowCount() const { return borrowCount; }
    void setBorrowCount(int count) { borrowCount = count; }

    void addBook() {
        std::cout << "Input Book ID: ";
        std::cin >> id;
        std::cin.ignore();
        std::cout << "Input Book Title: ";
        std::getline(std::cin, title);
        std::cout << "Input Book Author: ";
        std::getline(std::cin, author);
        std::cout << "Input Book Genre: ";
        std::getline(std::cin, genre);
        std::cout << "Input Book Total Copies: ";
        std::cin >> totalCopies;
        if (totalCopies < 0) totalCopies = 0;
        availableCopies = totalCopies;
    }

    void showBook() const {
        std::cout << "ID: " << id
                  << " | Title: " << title
                  << " | Author: " << author
                  << " | Genre: " << genre
                  << " | Total Copies: " << totalCopies
                  << " | Available Copies: " << availableCopies
                  << " | Borrow Count: " << borrowCount
                  << std::endl;
    }

    void borrowBook() {
        if (availableCopies > 0) {
            availableCopies--;
            borrowCount++;
            std::cout << "Book '" << title << "' successfully borrowed." << std::endl;
        } else {
            std::cout << "Book '" << title << "' not available." << std::endl;
        }
    }

    void returnBook() {
        if (availableCopies < totalCopies) {
            availableCopies++;
            std::cout << "Book '" << title << "' successfully returned." << std::endl;
        } else {
            std::cout << "All copies of '" << title << "' are already available." << std::endl;
        }
    }

private:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    int totalCopies;
    int availableCopies;
    int borrowCount;
};

class User : public Person {
private:
    int borrowedBookIDs[3];
    time_t borrowDates[3];
    int borrowedCount;
public:
    User() : borrowedCount(0) {
        for (int i = 0; i < 3; ++i) {
            borrowedBookIDs[i] = -1;
            borrowDates[i] = 0;
        }
    }

    bool login(const std::string& uname, const std::string& pass) override {
        return uname == username && pass == password;
    }

    void registerUser() {
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
    }

    void borrowBook(Book books[], int totalBooks) {
        if (borrowedCount >= 3) {
            std::cout << "You have reached the maximum number of books (3)." << std::endl;
            return;
        }
        int id;
        std::cout << "Input Book ID: ";
        std::cin >> id;
        for (int i = 0; i < totalBooks; ++i) {
            if (books[i].getID() == id) {
                books[i].borrowBook();
                borrowedBookIDs[borrowedCount] = id;
                borrowDates[borrowedCount] = time(nullptr);
                borrowedCount++;
                return;
            }
        }
        std::cout << "Book with this ID not found." << std::endl;
    }

    void returnBook(Book books[], int totalBooks) {
        if (borrowedCount == 0) {
            std::cout << "You haven't borrowed any books." << std::endl;
            return;
        }
        int id;
        std::cout << "Input Book ID: ";
        std::cin >> id;
        for (int i = 0; i < borrowedCount; ++i) {
            if (borrowedBookIDs[i] == id) {
                for (int j = 0; j < totalBooks; ++j) {
                    if (books[j].getID() == id) {
                        books[j].returnBook();
                        time_t now = time(nullptr);
                        double days = difftime(now, borrowDates[i]) / (60 * 60 * 24);
                        if (days > 7) {
                            double fine = (days - 7) * 1.0;
                            std::cout << "Fine for late return: " << fine << " units." << std::endl;
                        }
                        for (int k = i; k < borrowedCount - 1; ++k) {
                            borrowedBookIDs[k] = borrowedBookIDs[k + 1];
                            borrowDates[k] = borrowDates[k + 1];
                        }
                        borrowedBookIDs[borrowedCount - 1] = -1;
                        borrowDates[borrowedCount - 1] = 0;
                        borrowedCount--;
                        return;
                    }
                }
            }
        }
        std::cout << "You didn't borrow a book with that ID." << std::endl;
    }

    void viewBorrowedBooks(Book books[], int totalBooks) const {
        if (borrowedCount == 0) {
            std::cout << "No borrowed books." << std::endl;
            return;
        }
        std::cout << "Your borrowed books:" << std::endl;
        for (int i = 0; i < borrowedCount; ++i) {
            for (int j = 0; j < totalBooks; ++j) {
                if (books[j].getID() == borrowedBookIDs[i]) {
                    books[j].showBook();
                }
            }
        }
    }
};

class Admin : public Person {
public:
    Admin() { username = "admin"; password = "admin"; }
    bool login(const std::string& uname, const std::string& pass) override {
        return uname == username && pass == password;
    }

    void addBook(Book books[], int &totalBooks) {
        if (totalBooks >= 100) { // Предполагаем максимум 100 книг
            std::cout << "Library is full, cannot add more books." << std::endl;
            return;
        }
        books[totalBooks].addBook();
        totalBooks++;
        std::cout << "Book successfully added!" << std::endl;
    }

    void removeBook(Book books[], int &totalBooks) {
        if (totalBooks == 0) {
            std::cout << "No books to remove." << std::endl;
            return;
        }
        int id;
        std::cout << "Enter book ID to remove: ";
        std::cin >> id;
        for (int i = 0; i < totalBooks; ++i) {
            if (books[i].getID() == id) {
                for (int j = i; j < totalBooks - 1; ++j) {
                    books[j] = books[j + 1];
                }
                totalBooks--;
                std::cout << "Book removed." << std::endl;
                return;
            }
        }
        std::cout << "Book with this ID not found." << std::endl;
    }

    void viewAllBooks(Book books[], int totalBooks) const {
        if (totalBooks == 0) {
            std::cout << "No books in the library." << std::endl;
            return;
        }
        std::cout << "\n=== List of all books ===" << std::endl;
        for (int i = 0; i < totalBooks; ++i) {
            books[i].showBook();
        }
    }

    void viewUsers(User users[], int totalUsers) const {
        if (totalUsers == 0) {
            std::cout << "No users registered." << std::endl;
            return;
        }
        std::cout << "\n=== List of users ===" << std::endl;
        for (int i = 0; i < totalUsers; ++i) {
            std::cout << i + 1 << ". " << users[i].getUsername() << std::endl;
        }
    }
};

class Library {
private:
    static Library* instance;
    std::vector<Book> books;
    std::vector<User> users;
    int currentUserIndex; // Для отслеживания текущего пользователя

    Library() : currentUserIndex(-1) {}

public:
    static Library& getInstance() {
        if (!instance) {
            instance = new Library();
        }
        return *instance;
    }

    void addBook(Book& book) {
        books.push_back(book);
    }

    void addUser(User& user) {
        users.push_back(user);
    }

    Book* getBooksArray(int& size) {
        size = books.size();
        if (size == 0) return nullptr;
        Book* array = new Book[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = books[i];
        }
        return array;
    }

    User* getUsersArray(int& size) {
        size = users.size();
        if (size == 0) return nullptr;
        User* array = new User[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = users[i];
        }
        return array;
    }

    void setCurrentUserIndex(int index) {
        currentUserIndex = index;
    }

    int getCurrentUserIndex() const {
        return currentUserIndex;
    }

    void updateBook(int index, const Book& book) {
        if (index >= 0 && index < static_cast<int>(books.size())) {
            books[index] = book;
        }
    }
};

// Инициализация статического члена
Library* Library::instance = nullptr;

void searchBooks() {
    Library& library = Library::getInstance();
    int size;
    Book* books = library.getBooksArray(size);
    if (!books) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    std::string query;
    std::cout << "Enter search query (title, author, or genre): ";
    std::cin.ignore();
    std::getline(std::cin, query);
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].getTitle().find(query) != std::string::npos ||
            books[i].getAuthor().find(query) != std::string::npos ||
            books[i].getGenre().find(query) != std::string::npos) {
            books[i].showBook();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No books found matching the query." << std::endl;
    }
    delete[] books;
}

void topBooks() {
    Library& library = Library::getInstance();
    int size;
    Book* books = library.getBooksArray(size);
    if (!books) {
        std::cout << "No books in the library." << std::endl;
        return;
    }
    std::cout << "Top borrowed books (unsorted due to no <algorithm>):" << std::endl;
    for (int i = 0; i < size; ++i) {
        books[i].showBook();
        std::cout << "Borrowed " << books[i].getBorrowCount() << " times." << std::endl;
    }
    delete[] books;
}

void userMenu() {
    Library& library = Library::getInstance();
    int currentUserIndex = library.getCurrentUserIndex();
    if (currentUserIndex < 0) {
        std::cout << "No user logged in." << std::endl;
        return;
    }
    int size;
    User* users = library.getUsersArray(size);
    if (!users) {
        std::cout << "No users in the library." << std::endl;
        return;
    }
    Book* books = library.getBooksArray(size);
    if (!books) {
        std::cout << "No books in the library." << std::endl;
        delete[] users;
        return;
    }
    int input = 0;
    while (true) {
        std::cout << "=======USER MENU=======" << std::endl;
        std::cout << "1. Borrow book" << std::endl;
        std::cout << "2. Return book" << std::endl;
        std::cout << "3. View borrowed books" << std::endl;
        std::cout << "4. View all books" << std::endl;
        std::cout << "5. Search books" << std::endl;
        std::cout << "6. Logout" << std::endl;
        std::cout << "Input number: ";
        std::cin >> input;
        std::cin.ignore();
        switch (input) {
            case 1:
                users[currentUserIndex].borrowBook(books, size);
                for (int i = 0; i < size; ++i) {
                    library.updateBook(i, books[i]);
                }
                break;
            case 2:
                users[currentUserIndex].returnBook(books, size);
                for (int i = 0; i < size; ++i) {
                    library.updateBook(i, books[i]);
                }
                break;
            case 3:
                users[currentUserIndex].viewBorrowedBooks(books, size);
                break;
            case 4: {
                Admin admin;
                admin.viewAllBooks(books, size);
                break;
            }
            case 5:
                searchBooks();
                break;
            case 6:
                std::cout << "Logged out!" << std::endl;
                library.setCurrentUserIndex(-1);
                delete[] books;
                delete[] users;
                return;
            default:
                std::cout << "Invalid input. Choose 1-6." << std::endl;
                break;
        }
    }
}

void adminMenu() {
    Library& library = Library::getInstance();
    Admin admin;
    int size;
    Book* books = library.getBooksArray(size);
    if (!books) {
        books = new Book[100]; // Резервный массив, если пусто
        size = 0;
    }
    User* users = library.getUsersArray(size);
    if (!users) {
        users = new User[100];
        size = 0;
    }
    int input = 0;
    while (true) {
        std::cout << "=======ADMIN MENU=======" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. Remove book" << std::endl;
        std::cout << "3. View all books" << std::endl;
        std::cout << "4. View users" << std::endl;
        std::cout << "5. Search books" << std::endl;
        std::cout << "6. View top books" << std::endl;
        std::cout << "7. Logout" << std::endl;
        std::cout << "Input number: ";
        std::cin >> input;
        std::cin.ignore();
        switch (input) {
            case 1:
                admin.addBook(books, size);
                for (int i = 0; i < size; ++i) {
                    library.updateBook(i, books[i]);
                }
                if (size < 100) {
                    library.addBook(books[size - 1]);
                }
                break;
            case 2:
                admin.removeBook(books, size);
                for (int i = 0; i < size; ++i) {
                    library.updateBook(i, books[i]);
                }
                break;
            case 3:
                admin.viewAllBooks(books, size);
                break;
            case 4:
                admin.viewUsers(users, size);
                break;
            case 5:
                searchBooks();
                break;
            case 6:
                topBooks();
                break;
            case 7:
                std::cout << "Logged out!" << std::endl;
                delete[] books;
                delete[] users;
                return;
            default:
                std::cout << "Invalid input. Choose 1-7." << std::endl;
                break;
        }
    }
}

void loginMenu() {
    Library& library = Library::getInstance();
    Admin admin;
    int size;
    User* users = library.getUsersArray(size);
    if (!users) {
        users = new User[100];
        size = 0;
    }
    int input = 0;
    while (true) {
        std::cout << "=======MAIN MENU=======" << std::endl;
        std::cout << "1. Login as Admin" << std::endl;
        std::cout << "2. Login as User" << std::endl;
        std::cout << "3. Register as User" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Input number: ";
        std::cin >> input;
        std::cin.ignore();
        switch (input) {
            case 1: {
                std::string uname, pass;
                std::cout << "Admin Login: ";
                std::cin >> uname;
                std::cout << "Admin Password: ";
                std::cin >> pass;
                if (admin.login(uname, pass)) {
                    std::cout << "Admin logged in!" << std::endl;
                    adminMenu();
                } else {
                    std::cout << "Invalid admin credentials." << std::endl;
                }
                break;
            }
            case 2: {
                std::string uname, pass;
                std::cout << "User Login: ";
                std::cin >> uname;
                std::cout << "User Password: ";
                std::cin >> pass;
                for (int i = 0; i < size; ++i) {
                    if (users[i].login(uname, pass)) {
                        std::cout << "User logged in!" << std::endl;
                        library.setCurrentUserIndex(i);
                        userMenu();
                        delete[] users;
                        return;
                    }
                }
                std::cout << "Invalid user credentials." << std::endl;
                break;
            }
            case 3: {
                if (size >= 100) {
                    std::cout << "User limit reached." << std::endl;
                    break;
                }
                User newUser;
                newUser.registerUser();
                library.addUser(newUser);
                users = library.getUsersArray(size);
                std::cout << "User registered!" << std::endl;
                break;
            }
            case 4:
                std::cout << "Goodbye!" << std::endl;
                delete[] users;
                return;
            default:
                std::cout << "Invalid input. Choose 1-4." << std::endl;
                break;
        }
        delete[] users;
        users = library.getUsersArray(size);
    }
}

int main() {
    loginMenu();
    return 0;
}
