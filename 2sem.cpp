#include<iostream>
using namespace std;

class Book {
    string title, author;
    int year;
    public:
        Book() title("Unknown"), author("Unknown"), year(0) {}
        Book(string t, string a, int y) : title(t), author(a), year(y) {}
        // Acessories
        string get_title() {return title; }
        string get_author() {return author; }
        int get_year() {return year; }

        //Mutators 
        void set_title(string t) {title = t;}
        void set_author(string a) {
            if (a >= 1450) {
                author = a;
            }
            else {
                cout << "Invalid Year!! No book were developed then!!!" << endl;
            }
        };
        void set_year(int y) {year = y;}
        // display function
        void display() {
            cout << "==== Book info ====" << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Year: " << year << endl;
        }
};

int main() {
    Book b1;
    b1.display();
    Book b2("The NoteBook", "Nicholas John", 1997);
    b2.display();
    return 0;
}