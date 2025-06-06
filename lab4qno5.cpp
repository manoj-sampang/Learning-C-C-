/*Create a class PositiveInteger that represents a positive integer. Implement an
overloaded unary operator - to perform negation on a positive integer and return its
negated value. The PositiveInteger class should ensure that the value remains positive
at all times, even after negation.*/
#include<iostream>
using namespace std;

class PositiveInteger {
    int p_int;

public:
    // Constructor
    PositiveInteger(int val = 0) {
        if (val < 0) {
            p_int = -val; // Ensure it's positive
        } else {
            p_int = val;
        }
    }

    // Input function
    void input() {
        cout << "Enter any integer = ";
        cin >> p_int;
        if (p_int < 0) {
            p_int = -p_int; // Make it positive
        }
    }

    // Overload unary minus operator
    PositiveInteger operator-() {
        // Return the same value since the class ensures positivity
        return PositiveInteger(p_int);
    }

    // Friend function to display the object using cout
    friend ostream& operator<<(ostream& out, const PositiveInteger& obj);
};

// Overload << operator
ostream& operator<<(ostream& out, const PositiveInteger& obj) {
    out << obj.p_int;
    return out;
}

int main() {
    PositiveInteger p, res;
    p.input();

    res = -p; // Unary minus applied, still positive
    cout << "The value after negation is = " << res << endl;

    return 0;
}
