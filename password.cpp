#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

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

int main() {
    string password = "";
    char ch;

    cout << "Enter password: ";
    cout.flush();  // Make sure "Enter password:" appears immediately

    while ((ch = getch()) != '\n') {  // Enter key to finish
        if (ch == 127 || ch == 8) {  // Handle Backspace (Delete key on macOS is 127, sometimes 8)
            if (!password.empty()) {
                password.pop_back();
                // Move cursor back, print space, move back again to erase *
                cout << "\b \b";
                cout.flush();
            }
        } else if (ch >= 32 && ch <= 126) { // Printable characters only
            password += ch;
            cout << '*';
            cout.flush();
        }
        // else ignore other control characters
    }

    cout << "\nPassword saved: " << password << endl;
    return 0;
}
