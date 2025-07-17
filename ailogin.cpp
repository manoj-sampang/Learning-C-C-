#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

char getch() {
    char buf = 0;
    termios old = {};
    tcgetattr(STDIN_FILENO, &old);
    termios new_t = old;
    new_t.c_lflag &= ~ICANON; // disable buffered i/o
    new_t.c_lflag &= ~ECHO;   // disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
    read(STDIN_FILENO, &buf, 1); // read 1 byte
    tcsetattr(STDIN_FILENO, TCSANOW, &old); // restore
    return buf;
}

int main() {
    string password = "";
    char ch;

    cout << "Enter password: ";

    while ((ch = getch()) != '\n') {
        if (ch == 127 || ch == 8) { // Backspace for macOS and Linux
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // erase last '*'
            }
        } else {
            password += ch;
            cout << '*';
        }
    }

    cout << "\nPassword saved: " << password << endl;
    return 0;
}
