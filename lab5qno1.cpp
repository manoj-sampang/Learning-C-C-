/*Create a class PositiveInteger that represents a positive integer. Implement
an overloaded unary operator - to perform negation on a positive integer
and return its negated value. The PositiveInteger class should ensure that
the value remains positive at all times, even after negation. Use friend
function to overload unary operator -I*/
#include<iostream>
using namespace std;

class PositiveInteger {
    int n;

    public:
    PositiveInteger() {
        n = 0;
    }
    PositiveInteger(int num) {
        if (num < 0) {
            n = -num;
        }
        else {
            n = num;
        }
    }
    friend PositiveInteger operator-(const PositiveInteger &p);
    void display();
    int& access_n() {
        return n;
    }
    
};

void PositiveInteger::display() {
    cout << n << endl;
}
PositiveInteger operator-(const PositiveInteger &p) {

    return PositiveInteger(-p.n);

}

int main() {
    PositiveInteger p1;
    cout << "Enter any number you want to negate" << endl;
    cin >> p1.access_n();
    cout << "Before Negating" << endl;
    p1.display();
    cout << "After Negating" << endl;
    PositiveInteger p2 = -p1;
    p2.display();
    return 0;
}