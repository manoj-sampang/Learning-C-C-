/*Write a menu driven program to compute a^n where a is non-zero real number and n is a positive integer and also 
find the factorial of a number using recursion*/

#include<iostream>
using namespace std;

class Recursion {
    int n, f;
    float a;
public:
    Recursion() {
        n = f = 0;
        a = 0.0;
    }

    Recursion(int fact, int power, float coefficient) {
        f = fact;
        n = power;
        a = coefficient;
    }

    int factorial(int fact) {
        if (fact <= 1) return 1;
        return fact * factorial(fact - 1);
    }

    float power(float a, int pow) {
        if (pow == 0) return 1;
        return a * power(a, pow - 1);
    }
};

int main() {
    int choice, fact, pow;
    float coef;

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. Factorial\n2. a^n (Power)\n3. Quit\n";
        cout << "Choose (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter number to find factorial: ";
                cin >> fact;
                Recursion r;
                int result = r.factorial(fact);
                cout << "Factorial of " << fact << " = " << result << endl;
                break;
            }
            case 2: {
                cout << "Enter base (a): ";
                cin >> coef;
                cout << "Enter exponent (n): ";
                cin >> pow;
                if (pow < 0) {
                    cout << "Exponent should be a non-negative integer.\n";
                    break;
                }
                Recursion r;
                float result = r.power(coef, pow);
                cout << coef << "^" << pow << " = " << result << endl;
                break;
            }
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
