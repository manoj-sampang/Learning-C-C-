/*Create a C++ class called Fraction that represents a fraction with private
member variables numerator and denominator. Implement a non-member
function called multiply() that takes two Fraction objects as parameters and
returns the result of multiplying the fractions together as a new Fraction
object. Make the multiply() function a friend of the Fraction class using
the friend keyword. Demonstrate the usage of the multiply() function in a
program.*/

#include<iostream>
using namespace std;

class Fraction {
    int nume, deno;
    public:
        void input() {
            cout << "Enter the asked info" << endl;
            cout << "--- Fraction Multiplication ---" << endl;
            cout << "Numerator: ";
            cin >> nume;
            cout << "Denominator: ";
            cin >> deno;
        }
        friend Fraction multiply(Fraction f1, Fraction f2);
        void display() {
            cout << "=== Multiplied Result ===" << endl;
            cout << "Ans: " << nume << "/" << deno << endl;
        }
};
Fraction multiply(Fraction f1, Fraction f2) {
    Fraction temp;
    temp.nume = f1.nume * f2.nume;
    temp.deno = f1.deno * f2.deno;
    return temp;
}

int main() {
    Fraction f1, f2, result;
    f1.input();
    f2.input();
    result = multiply(f1, f2);
    result.display();
    return 0;
}
