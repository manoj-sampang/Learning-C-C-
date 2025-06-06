/*WAP to implement endl, setw, setprecision,fixed and scientific Manipulator.*/
#include <iostream>
#include <iomanip> // for manipulators
using namespace std;

int main() {
    float num1 = 123.456789;
    float num2 = 0.000123456;

    cout << "Using endl:" << endl;
    cout << "This is line 1" << endl;
    cout << "This is line 2" << endl;

    cout << "\nUsing setw:" << endl;
    cout << setw(10) << "Number" << setw(15) << "CATASTROPY" << endl;
    cout << setw(10) << "num1" << setw(15) << num1 << endl;
    cout << setw(10) << "num2" << setw(15) << num2 << endl;

    cout << "\nUsing setprecision (without fixed):" << endl;
    cout << setprecision(4) << num1 << endl;

    cout << "\nUsing fixed and setprecision:" << endl;
    cout << fixed << setprecision(4) << num1 << endl;

    cout << "\nUsing scientific and setprecision:" << endl;
    cout << scientific << setprecision(4) << num2 << endl;

    return 0;
}
