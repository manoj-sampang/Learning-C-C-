/*Create a Scientific Calculator program using two classes, Calculator and
MathOperations, where MathOperations is a Friend class of Calculator.
The Calculator class has private data members for two input values and
public member functions for initialization and data retrieval. The
MathOperations class contains static member functions for addition,
subtraction, multiplication, and division operations, and it can access the
private data members of the Calculator class. Implement the classes in C++
and demonstrate the scientific calculator's functionality with appropriate
test cases.*/

#include<iostream>
using namespace std;

class Calculator; // Forward declaration

class MathOperations {
public:
    static void add(Calculator c);
    static void sub(Calculator c);
    static void mul(Calculator c);
    static void div(Calculator c);
};

class Calculator {
private:
    double value1, value2;

public:
    void input() {
        cout << "Give any two values for our operands" << endl;
        cout << "Operand 1: ";
        cin >> value1;
        cout << "Operand 2: ";
        cin >> value2;
    }

    // Declare MathOperations as a friend class
    friend class MathOperations;
};

// Define static methods with Calculator parameter
void MathOperations::add(Calculator c) {
    cout << "Adding two values\nResult: " << c.value1 + c.value2 << endl;
}
void MathOperations::sub(Calculator c) {
    cout << "Subtracting two values\nResult: " << c.value1 - c.value2 << endl;
}
void MathOperations::mul(Calculator c) {
    cout << "Multiplying two values\nResult: " << c.value1 * c.value2 << endl;
}
void MathOperations::div(Calculator c) {
    if (c.value2 != 0)
        cout << "Dividing two values\nResult: " << c.value1 / c.value2 << endl;
    else
        cout << "Error: Division by zero!" << endl;
}

int main() {
    Calculator C;
    C.input();

    cout << "\n=== Addition ===" << endl;
    MathOperations::add(C);

    cout << "\n=== Subtraction ===" << endl;
    MathOperations::sub(C);

    cout << "\n=== Multiplication ===" << endl;
    MathOperations::mul(C);

    cout << "\n=== Division ===" << endl;
    MathOperations::div(C);

    return 0;
}
