/*
=============================================================================
                    C++ BASICS - LESSON 1
=============================================================================

This lesson covers the fundamental concepts used in our Library Management System.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. CLASSES AND OBJECTS
// A class is a blueprint for creating objects
class SimpleBook {
private:
    // Private members - can only be accessed within the class
    string title;
    string author;
    int pages;
    
public:
    // Constructor - special function called when object is created
    SimpleBook() {
        title = "Unknown";
        author = "Unknown";
        pages = 0;
        cout << "Default constructor called!\n";
    }
    
    // Parameterized constructor
    SimpleBook(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
        cout << "Parameterized constructor called!\n";
    }
    
    // Destructor - called when object is destroyed
    ~SimpleBook() {
        cout << "Destructor called for: " << title << "\n";
    }
    
    // Getter methods (accessors)
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPages() const { return pages; }
    
    // Setter methods (mutators)
    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setPages(int p) { 
        if (p > 0) pages = p; 
        else cout << "Invalid page count!\n";
    }
    
    // Member function
    void displayInfo() const {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Pages: " << pages << "\n";
        cout << "------------------------\n";
    }
};

// 2. FUNCTION EXAMPLES
void demonstrateBasics() {
    cout << "\n=== BASIC CONCEPTS DEMONSTRATION ===\n\n";
    
    // Creating objects
    cout << "1. Creating objects:\n";
    SimpleBook book1;  // Default constructor
    SimpleBook book2("1984", "George Orwell", 328);  // Parameterized constructor
    
    cout << "\n2. Using getter methods:\n";
    cout << "Book1 title: " << book1.getTitle() << "\n";
    cout << "Book2 title: " << book2.getTitle() << "\n";
    
    cout << "\n3. Using setter methods:\n";
    book1.setTitle("To Kill a Mockingbird");
    book1.setAuthor("Harper Lee");
    book1.setPages(281);
    
    cout << "\n4. Displaying book information:\n";
    book1.displayInfo();
    book2.displayInfo();
    
    // 5. VECTORS (Dynamic Arrays)
    cout << "5. Working with vectors:\n";
    vector<SimpleBook> library;
    
    // Adding books to vector
    library.push_back(book1);
    library.push_back(book2);
    library.push_back(SimpleBook("Brave New World", "Aldous Huxley", 268));
    
    cout << "Library contains " << library.size() << " books:\n";
    
    // Iterating through vector
    for (int i = 0; i < library.size(); i++) {
        cout << "Book " << (i+1) << ": " << library[i].getTitle() << "\n";
    }
    
    // Modern C++ range-based for loop
    cout << "\nUsing range-based for loop:\n";
    for (const auto& book : library) {
        cout << "- " << book.getTitle() << " by " << book.getAuthor() << "\n";
    }
}

// 3. POINTERS AND REFERENCES
void demonstratePointersAndReferences() {
    cout << "\n=== POINTERS AND REFERENCES ===\n\n";
    
    SimpleBook book("The Catcher in the Rye", "J.D. Salinger", 277);
    
    // Reference - alias for existing variable
    SimpleBook& bookRef = book;
    cout << "Original title: " << book.getTitle() << "\n";
    bookRef.setTitle("Modified via reference");
    cout << "After reference modification: " << book.getTitle() << "\n";
    
    // Pointer - stores memory address
    SimpleBook* bookPtr = &book;
    cout << "Title via pointer: " << bookPtr->getTitle() << "\n";
    bookPtr->setAuthor("Modified Author");
    cout << "Author after pointer modification: " << book.getAuthor() << "\n";
    
    // Dynamic memory allocation
    SimpleBook* dynamicBook = new SimpleBook("Dynamic Book", "Dynamic Author", 100);
    cout << "Dynamic book title: " << dynamicBook->getTitle() << "\n";
    delete dynamicBook;  // Important: free memory!
}

int main() {
    cout << "=============================================================================\n";
    cout << "                    C++ BASICS TUTORIAL\n";
    cout << "=============================================================================\n";
    
    demonstrateBasics();
    demonstratePointersAndReferences();
    
    cout << "\n=== END OF LESSON 1 ===\n";
    return 0;
}