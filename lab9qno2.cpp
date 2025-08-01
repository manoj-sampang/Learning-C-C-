/*You are working on a library management system. Your task is to
implement two classes, Book and Library, such that the library’s member
function becomes a friend function of Book. Class Book represents a book
in the library. It has private data members for the book's title, author, and
book ID. Class Library represents the library itself. It has an array to store
Book objects and a member function called 'displayBookDetails' that takes
a Book object as input and displays its details.
Your task is to implement the classes and their member functions so that
'displayBookDetails' in Library becomes a friend function of Book,
allowing it to access the private data members of the Book and display its
details.*/

#include<iostream>
using namespace std;

class Book; // Forward declaration

class Library {
public:
    // Member function that takes a Book and displays its details
    void displayBookDetails(const Book& b);
};

class Book {
private:
    string title, author, id;

public:
    void input() {
        cout << "=== Book Input ===" << endl;
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Book ID: ";
        getline(cin, id);
    }

    // Declaring Library::displayBookDetails as a friend
    friend void Library::displayBookDetails(const Book& b);
};

// Definition of the friend function
void Library::displayBookDetails(const Book& b) {
    cout << "\n=== Book Details ===" << endl;
    cout << "Title: " << b.title << endl;
    cout << "Author: " << b.author << endl;
    cout << "Book ID: " << b.id << endl;
}

int main() {
    Book b1;
    Library lib;

    b1.input(); // User inputs details
    lib.displayBookDetails(b1); // Access private members via friend function

    return 0;
}
