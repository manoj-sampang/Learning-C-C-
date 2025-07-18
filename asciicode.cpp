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
    char ch;
    cout << "Press keys, 'q' to quit:\n";

    while ((ch = getch()) != 'q') {
        cout << "ASCII: " << (int)ch << ", Char: " << ch << endl;
    }

    cout << "Quit!\n";
    return 0;
}
