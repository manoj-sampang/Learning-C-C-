/*You are given a Rational class that represents rational numbers (fractions).
The class has two private member variables: numerator (to store the
numerator) and denominator (to store the denominator) of the rational
number. Your task is to overload the binary operators +, -, *, and / for this
class to perform arithmetic operations with rational numbers. Make sure to
simplify the rational numbers after performing arithmetic operations to
represent them in their simplest form (i.e., with the smallest possible
integer numerator and denominator). You may assume that the input
rational numbers will have valid values, and the denominator will never be
zero.*/
#include<iostream>
using namespace std;

class Rational {
    int nume;
    int deno;
    public:
    Rational () {
        nume = deno = 0;
    }
    Rational(int n, int d) {
        nume = n;
        deno = d;
        simplify_check();
    }
    void simplify_check() {
        for(int i = ((nume > deno)? nume:deno); i > 1; --i) {
            if(nume%i == 0 && deno%i == 0) {
                simplify(i);
            }
        }
    }
    void simplify(int factor) {
        nume /= factor;
        deno /= factor;
    }
    void input () {
        cout << "Enter the asked info" << endl;
        cout << "Numerator: ";
        cin >> nume;
        cout << "Denominator: ";
        cin >> deno;
    }
    void display() {
        cout << "Ans: " << nume << "/" << deno << endl;
    }
    Rational operator+(Rational &r) {
        return Rational((nume*r.deno)+(deno*r.nume),deno*r.deno);
    }
    Rational operator-(Rational &r) {
        return Rational((nume*r.deno)-(deno*r.nume),deno*r.deno);
    }
    Rational operator*(Rational &r) {
        return Rational(nume*r.nume,deno*r.deno);
    }
    Rational operator/(Rational &r) {
        return Rational(nume*r.deno,deno*r.nume);
    }
};

int main() {
    Rational r1,r2,res;
    cout << "Enter the first Rational number" << endl;
    r1.input();
    cout << "Enter the second Rational number" << endl;
    r2.input();
    cout << "Addition" << endl;
    res = r1+r2;
    res.display();
    cout << "Substraction" << endl;
    res = r1-r2;
    res.display();
    cout << "Multiplication" << endl;
    res = r1*r2;
    res.display();
    cout << "Division" << endl;
    res = r1/r2;
    res.display();
    return 0;
}