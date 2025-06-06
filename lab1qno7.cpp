#include <iostream>
#include <string>
using namespace std;

// Swap two integers
void swap(int &x, int &y) {
    x -= y;
    y = x + y;
    x = y - x;
    cout << "After Swapping Integers: num1 = " << x << ", num2 = " << y << endl;
}

// Swap two floats
void swap(float &x, float &y) {
    x -= y;
    y = x + y;
    x = y - x;
    cout << "After Swapping Floats: num1 = " << x << ", num2 = " << y << endl;
}

// Swap two strings (C++ string version)
void swap(string &x, string &y) {
    string temp = x;
    x = y;
    y = temp;
    cout << "After Swapping Strings: str1 = " << x << ", str2 = " << y << endl;
}

int main() {
    int i1, i2;
    float f1, f2;
    string s1, s2;

    cout << "Enter two Integers:" << endl;
    cout << "num1 = ";
    cin >> i1;
    cout << "num2 = ";
    cin >> i2;

    cout << "Enter two Float numbers to swap:" << endl;
    cout << "num1 = ";
    cin >> f1;
    cout << "num2 = ";
    cin >> f2;

    cin.ignore(); // Clear input buffer before getline

    cout << "Enter two Strings to swap:" << endl;
    cout << "str1 = ";
    getline(cin, s1);
    cout << "str2 = ";
    getline(cin, s2);

    cout << "\n--------------- BEFORE SWAPPING ----------------" << endl;
    cout << "Integers: num1 = " << i1 << ", num2 = " << i2 << endl;
    cout << "Floats:   num1 = " << f1 << ", num2 = " << f2 << endl;
    cout << "Strings:  str1 = " << s1 << ", str2 = " << s2 << endl;

    cout << "\n--------------- AFTER SWAPPING ----------------" << endl;
    swap(i1, i2);
    swap(f1, f2);
    swap(s1, s2);

    return 0;
}
