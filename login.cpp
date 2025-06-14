#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // Hardcoded user credentials (replace with file reading for production)
    map<string, string> users = {
        {"john", "1234"},
        {"admin", "password"}
    };

    string username, password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    if (users.count(username) > 0 && users[username] == password) {
        cout << "Login successful!" << endl;
        // Add code here to proceed to the next part of your application
    } else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}