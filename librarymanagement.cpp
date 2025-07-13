#include<iostream>
using namespace std;
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

class Register {
    string username, password;
    void 
};

class Login {
    string username;
    string password;
        Login() {
            username = "no username";
            password = "no password";
        }
        void input() {
            cout << "Permission Accessed"z << endl;
            cout << "username: ";
            getline(cin, username);
            cout << "password: ";
            getline(cin, password);
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