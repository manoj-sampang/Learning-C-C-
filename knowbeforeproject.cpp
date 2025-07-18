/*
=============================================================================
                    LIBRARY SYSTEM BREAKDOWN - LESSON 4
=============================================================================

This lesson breaks down the actual Library Management System code,
explaining each component and how they work together.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <termios.h>
#include <unistd.h>
#include <ctime>

using namespace std;

/*
=============================================================================
1. PASSWORD MASKING UTILITY
=============================================================================
This function allows secure password input by hiding characters as they're typed.
*/

char getch() {
    char buf = 0;
    termios old = {};
    
    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &old);
    
    // Create new settings
    termios new_t = old;
    new_t.c_lflag &= ~ICANON;  // Disable canonical mode (line buffering)
    new_t.c_lflag &= ~ECHO;    // Disable echo (don't show typed characters)
    
    // Apply new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
    
    // Read one character
    read(STDIN_FILENO, &buf, 1);
    
    // Restore original settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    
    return buf;
}

string getHiddenPassword() {
    string password;
    char ch;
    
    cout << "Password: ";
    while ((ch = getch()) != '\n') {  // Continue until Enter is pressed
        if (ch == 127 || ch == 8) {  // Handle Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";  // Move cursor back, print space, move back again
                cout.flush();
            }
        } else if (ch >= 32 && ch <= 126) {  // Printable characters only
            password += ch;
            cout << '*';  // Show asterisk instead of actual character
            cout.flush();
        }
    }
    cout << endl;
    return password;
}

/*
=============================================================================
2. DATE HANDLING CLASS
=============================================================================
This class manages dates for the library system (join dates, due dates, etc.)
*/

class SimpleDate {
private:
    string dateString;
    
public:
    // Default constructor - sets to current date
    SimpleDate() {
        time_t now = time(0);           // Get current time
        tm* timeinfo = localtime(&now); // Convert to local time structure
        
        // Format as YYYY/MM/DD
        dateString = std::to_string(1900 + timeinfo->tm_year) + "/" +
                    std::to_string(1 + timeinfo->tm_mon) + "/" +
                    std::to_string(timeinfo->tm_mday);
    }
    
    // Constructor with specific date
    SimpleDate(const string& date) : dateString(date) {}
    
    string getDate() const { return dateString; }
    void setDate(const string& date) { dateString = date; }
    
    // Basic date validation
    bool isValid() const {
        return dateString.length() == 10 && 
               dateString[4] == '/' && 
               dateString[7] == '/';
    }
    
    // Compare dates (simple string comparison works for YYYY/MM/DD format)
    bool operator>(const SimpleDate& other) const {
        return dateString > other.dateString;
    }
};

/*
=============================================================================
3. SIMPLIFIED BOOK CLASS
=============================================================================
This demonstrates the core concepts of the Book class from our system.
*/

class SimpleBook {
private:
    string bookId;
    string title;
    string author;
    int totalCopies;
    int availableCopies;
    
public:
    // Default constructor
    SimpleBook() : totalCopies(0), availableCopies(0) {}
    
    // Parameterized constructor
    SimpleBook(const string& id, const string& t, const string& a, int total)
        : bookId(id), title(t), author(a), totalCopies(total), availableCopies(total) {}
    
    // Getters (const methods - don't modify the object)
    string getId() const { return bookId; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getTotalCopies() const { return totalCopies; }
    int getAvailableCopies() const { return availableCopies; }
    
    // Setters
    void setId(const string& id) { bookId = id; }
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setTotalCopies(int total) { totalCopies = total; }
    void setAvailableCopies(int available) { availableCopies = available; }
    
    // Business logic methods
    bool isAvailable() const { return availableCopies > 0; }
    
    bool borrowBook() {
        if (availableCopies > 0) {
            availableCopies--;
            return true;
        }
        return false;
    }
    
    void returnBook() {
        if (availableCopies < totalCopies) {
            availableCopies++;
        }
    }
    
    // Serialization - convert object to string for file storage
    string toString() const {
        stringstream ss;
        ss << bookId << "," << title << "," << author << "," 
           << totalCopies << "," << availableCopies;
        return ss.str();
    }
    
    // Deserialization - create object from string
    void fromString(const string& data) {
        stringstream ss(data);
        string item;
        
        getline(ss, bookId, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        
        getline(ss, item, ',');
        totalCopies = std::stoi(item);
        
        getline(ss, item, ',');
        availableCopies = std::stoi(item);
    }
    
    void display() const {
        cout << "ID: " << bookId << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Available: " << availableCopies << "/" << totalCopies << "\n";
        cout << "Status: " << (isAvailable() ? "Available" : "Not Available") << "\n";
    }
};

/*
=============================================================================
4. FILE MANAGEMENT SYSTEM
=============================================================================
This demonstrates how the library system saves and loads data.
*/

class SimpleLibrary {
private:
    vector<SimpleBook> books;
    const string BOOKS_FILE = "simple_books.txt";
    
public:
    // Load books from file
    void loadBooks() {
        ifstream file(BOOKS_FILE);
        if (!file.is_open()) {
            cout << "No existing book file found. Starting fresh.\n";
            return;
        }
        
        books.clear();  // Clear existing books
        string line;
        
        while (getline(file, line)) {
            if (!line.empty()) {
                SimpleBook book;
                book.fromString(line);
                books.push_back(book);
            }
        }
        
        file.close();
        cout << "Loaded " << books.size() << " books from file.\n";
    }
    
    // Save books to file
    void saveBooks() {
        ofstream file(BOOKS_FILE);
        if (!file.is_open()) {
            cout << "Error: Cannot save books to file!\n";
            return;
        }
        
        for (const auto& book : books) {
            file << book.toString() << "\n";
        }
        
        file.close();
        cout << "Saved " << books.size() << " books to file.\n";
    }
    
    // Add a new book
    void addBook() {
        string id, title, author;
        int copies;
        
        cout << "\n=== ADD NEW BOOK ===\n";
        cout << "Book ID: ";
        getline(cin, id);
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Total Copies: ";
        cin >> copies;
        cin.ignore();  // Clear input buffer
        
        SimpleBook newBook(id, title, author, copies);
        books.push_back(newBook);
        
        cout << "Book added successfully!\n";
        saveBooks();  // Auto-save
    }
    
    // Display all books
    void displayAllBooks() {
        cout << "\n=== ALL BOOKS ===\n";
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        
        for (const auto& book : books) {
            book.display();
            cout << "------------------------\n";
        }
    }
    
    // Search books by title
    void searchBooks() {
        string query;
        cout << "\n=== SEARCH BOOKS ===\n";
        cout << "Enter search term: ";
        getline(cin, query);
        
        vector<SimpleBook> results;
        for (const auto& book : books) {
            if (book.getTitle().find(query) != string::npos ||
                book.getAuthor().find(query) != string::npos) {
                results.push_back(book);
            }
        }
        
        if (results.empty()) {
            cout << "No books found matching '" << query << "'\n";
        } else {
            cout << "Found " << results.size() << " book(s):\n";
            for (const auto& book : results) {
                book.display();
                cout << "------------------------\n";
            }
        }
    }
    
    // Borrow a book
    void borrowBook() {
        string bookId;
        cout << "\n=== BORROW BOOK ===\n";
        cout << "Enter Book ID: ";
        getline(cin, bookId);
        
        for (auto& book : books) {
            if (book.getId() == bookId) {
                if (book.borrowBook()) {
                    cout << "Book borrowed successfully!\n";
                    cout << "Title: " << book.getTitle() << "\n";
                    cout << "Remaining copies: " << book.getAvailableCopies() << "\n";
                    saveBooks();  // Auto-save
                } else {
                    cout << "Sorry, this book is not available.\n";
                }
                return;
            }
        }
        
        cout << "Book with ID '" << bookId << "' not found.\n";
    }
    
    // Return a book
    void returnBook() {
        string bookId;
        cout << "\n=== RETURN BOOK ===\n";
        cout << "Enter Book ID: ";
        getline(cin, bookId);
        
        for (auto& book : books) {
            if (book.getId() == bookId) {
                book.returnBook();
                cout << "Book returned successfully!\n";
                cout << "Title: " << book.getTitle() << "\n";
                cout << "Available copies: " << book.getAvailableCopies() << "\n";
                saveBooks();  // Auto-save
                return;
            }
        }
        
        cout << "Book with ID '" << bookId << "' not found.\n";
    }
    
    // Simple menu system
    void run() {
        loadBooks();  // Load existing data
        
        while (true) {
            cout << "\n=== SIMPLE LIBRARY SYSTEM ===\n";
            cout << "1. Add Book\n";
            cout << "2. Display All Books\n";
            cout << "3. Search Books\n";
            cout << "4. Borrow Book\n";
            cout << "5. Return Book\n";
            cout << "6. Exit\n";
            cout << "Choose option: ";
            
            int choice;
            cin >> choice;
            cin.ignore();  // Clear input buffer
            
            switch (choice) {
                case 1: addBook(); break;
                case 2: displayAllBooks(); break;
                case 3: searchBooks(); break;
                case 4: borrowBook(); break;
                case 5: returnBook(); break;
                case 6: 
                    cout << "Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    }
};

/*
=============================================================================
5. DEMONSTRATION FUNCTIONS
=============================================================================
*/

void demonstratePasswordMasking() {
    cout << "\n=== PASSWORD MASKING DEMO ===\n";
    cout << "Try typing a password (it will show as asterisks):\n";
    string password = getHiddenPassword();
    cout << "You entered: " << password << "\n";
}

void demonstrateDateHandling() {
    cout << "\n=== DATE HANDLING DEMO ===\n";
    
    SimpleDate today;
    cout << "Today's date: " << today.getDate() << "\n";
    
    SimpleDate customDate("2024/12/25");
    cout << "Custom date: " << customDate.getDate() << "\n";
    cout << "Is custom date valid? " << (customDate.isValid() ? "Yes" : "No") << "\n";
    
    if (today > customDate) {
        cout << "Today is after the custom date\n";
    } else {
        cout << "Today is before or same as the custom date\n";
    }
}

void demonstrateBookOperations() {
    cout << "\n=== BOOK OPERATIONS DEMO ===\n";
    
    SimpleBook book("B001", "The C++ Programming Language", "Bjarne Stroustrup", 3);
    
    cout << "Initial book state:\n";
    book.display();
    
    cout << "\nBorrowing book...\n";
    if (book.borrowBook()) {
        cout << "Book borrowed successfully!\n";
    }
    book.display();
    
    cout << "\nBorrowing another copy...\n";
    book.borrowBook();
    book.display();
    
    cout << "\nReturning a book...\n";
    book.returnBook();
    book.display();
    
    cout << "\nSerialization demo:\n";
    string serialized = book.toString();
    cout << "Serialized: " << serialized << "\n";
    
    SimpleBook newBook;
    newBook.fromString(serialized);
    cout << "Deserialized book:\n";
    newBook.display();
}

int main() {
    cout << "=============================================================================\n";
    cout << "                    LIBRARY SYSTEM BREAKDOWN TUTORIAL\n";
    cout << "=============================================================================\n";
    
    int choice;
    while (true) {
        cout << "\n=== CHOOSE DEMONSTRATION ===\n";
        cout << "1. Password Masking\n";
        cout << "2. Date Handling\n";
        cout << "3. Book Operations\n";
        cout << "4. Run Simple Library System\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: demonstratePasswordMasking(); break;
            case 2: demonstrateDateHandling(); break;
            case 3: demonstrateBookOperations(); break;
            case 4: {
                SimpleLibrary library;
                library.run();
                break;
            }
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    
    return 0;
}