#include <iostream>
#include <fstream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Custom getch() for password input (Linux/macOS)
char getch() {
    char buf = 0;
    termios old = {};
    tcgetattr(STDIN_FILENO, &old);
    termios new_t = old;
    new_t.c_lflag &= ~ICANON;
    new_t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
    read(STDIN_FILENO, &buf, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return buf;
}

// Book class to handle book details
class Book {
    string id, title, author, year;

public:
    void input() {
        cout << "--- Enter Book Details ---\n";
        cout << "Book ID: ";
        getline(cin, id);
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Published Year: ";
        getline(cin, year);

        ofstream fout("book_details.txt", ios::app);
        if (fout.is_open()) {
            fout << id << "," << title << "," << author << "," << year << "\n";
            fout.close();
            cout << "Book saved successfully!\n";
        } else {
            cout << "Error: Could not open file to save book details.\n";
        }
    }

    void display() {
        ifstream fin("book_details.txt");
        if (fin.is_open()) {
            string line;
            cout << "\n--- Book Records ---\n";
            while (getline(fin, line)) {
                cout << line << endl;
            }
            fin.close();
        } else {
            cout << "No book records found.\n";
        }
    }
};

// Login class
class Login {
    string username, password;

public:
    void input() {
        cout << "--- User Login ---\n";
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";

        char ch;
        password = "";
        while ((ch = getch()) != '\n') {
            if (ch == 127 || ch == 8) {
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                }
            } else {
                password += ch;
                cout << '*';
            }
        }
        cout << "\n";

        ofstream fout("login.txt", ios::app);
        if (fout.is_open()) {
            fout << username << "," << password << "\n";
            fout.close();
            cout << "Login saved successfully!\n";
        } else {
            cout << "Error: Could not save login.\n";
        }
    }

    void showSavedLogins() {
        ifstream fin("login.txt");
        if (fin.is_open()) {
            string line;
            cout << "\n--- Saved Logins ---\n";
            while (getline(fin, line)) {
                cout << line << endl;
            }
            fin.close();
        } else {
            cout << "No saved logins found.\n";
        }
    }
};

int main() {
    Login user;
    Book book;

    user.input();
    user.showSavedLogins();

    book.input();
    book.display();

    return 0;
}
