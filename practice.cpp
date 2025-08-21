#include <iostream>
using namespace std;

int main() {
    char string1[50];
    cout << "Terminated by $" << endl;
    cout << "Write anything you want until you pressed $" << endl;
    cin.get(string1, 50, '$');
    cout << "The ouput" << endl;
    cout << string1 << endl;
    return 0;
}

//how to write in file
ofstream fout("Student.txt");