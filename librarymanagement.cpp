#include<iostream>
using namespace std;


class Identity {
    string name, date, book_info;
    public:
        void input() {
            cout << "Name: ";
            getline(cin, name);
        }


 


};
class LibraryManagement {
    string year;
    string title,author,id;
    public:
        Library() {
            Year = nullptr;
            title = nullptr;
            author = nullptr;
            id = nullptr;
        }
        void input() {

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
            if(getline(cin, password));
        }
    protected:
        void validity() {
            string user, pass;
            cout << "--- Validity Check ---" << endl;
            cout << "username: ";
            getline(cin, user);
            cout << "pass: ";
            getline(cin, pass);
            if (username == user && password = pass) input();
            else cout << "--- Access Denied, Enter your user and password again again ---" << endl;
        }
        
        
};
int main() {
    
    return 0;
}