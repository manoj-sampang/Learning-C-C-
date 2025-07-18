#include<iostream>
#include <termios.h>
#include <unistd.h>
#include <string>

using namespace std;

class LibraryManagement;
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

class Date{
    string time;
    public:
       string& get_time() {
            return time;
        }
};

class BookInfo : public LibraryManagement {
    
};
class Identity : public Date {
    public:
        void input() {
            cout << "Name of the student: ";
            getline(cin, name);
            cout << "Date(YYYY/MM/DD): ";
            getline(cin, get_time());
        }


 


};
class LibraryManagement {
    string year;
    string title,author,id;
    public:
        Library() {
            year = " ";
            title = " ";
            author = " ";
            id = " ";
        }
        void input() {
            cout << "--- Enter Book Details ---" << endl;
            ofstream BookFile("book_details.txt");
            if(BookFile.is_open()) {
                cout << "Book id: ";
                getline(cin, id);
                cout << "Title of the Book: ";
                getline(cin, title);
                cout << "Author of the Book: ";
                getline(cin, author);
                cout << "Published Year: ";
                getline(cin, year);
            }
            BookFile.close();
            else {
                cout << "Error Due to unable to Save the details" << endl;
            }
        }
        void display() {

        }
            
};

class Home {
    string 
};

class Register {
    string username, password;
    public:
        
};

class Login {
    string username;
    char ch;
    string password;
        Login() {
            username = "no username";
            password = "no password";
        }
        void input() {
            cout << "Permission Accessed" << endl;
            cout << "username: ";
            getline(cin, username);
            cout << "password: ";
            while ((ch = getch()) != '\n') {  // Enter key to finish
                if (ch == 127 || ch == 8) {  // Handle Backspace (Delete key on macOS is 127, sometimes 8)
                    if (!password.empty()) {
                        password.pop_back();
                            // Move cursor back, print space, move back again to erase *
                        cout << "\b \b";
                        cout.flush();
                    }
                } 
            else if (ch >= 32 && ch <= 126) { // Printable characters only
            password += ch;
            cout << '*';
            cout.flush();
            }
        // else ignore other control characters
        }
        ofstream accesspassword("password.txt");
        if(accesspassword.is_open()) {
            cout << "File Created for storing personal information" << endl;
            accesspassword << username << ", "<< password << endl;;
            cout << "Password Saved" << endl;
        }
        accesspassword.close();
        else {
            cout << "File couldn't be opened" << endl;
        } 
    }
    protected:
        bool validity() {
            string user, pass;
            cout << "--- Validity Check ---" << endl;
            cout << "username: ";
            getline(cin, user);
            cout << "pass: ";
            getline(cin, pass);
            if (username == user && password = pass) input();
            else {
                cout << "--- Access Denied, Enter your user and password again again ---" << endl;
            }
        }
        
        
};
int main() {
    
    return 0;
}