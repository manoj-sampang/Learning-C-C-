/*Write a menu driven program to find the total no. of permutations, total no. of combinations and to generate 
the permutations for the given input strings.*/

#include<iostream>
#include<string>
#include<algorithm> // for next_permutation
using namespace std;

class Permutations {
protected:
    int n, r;
public:
    void input() {
        cout << "-- Permutations-Combinations Calculations --" << endl;
        cout << "Enter total no. of objects to arrange from (n): ";
        cin >> n;
        cout << "Enter no. of arrangement at a time (r): ";
        cin >> r;
    }

    int get_n() { return n; }
    int get_r() { return r; }

    int factorial(int num) {
        int result = 1;
        for (int i = 1; i <= num; ++i)
            result *= i;
        return result;
    }

    virtual void display() {
        int perm = factorial(n) / factorial(n - r);
        cout << "Permutations P(" << n << ", " << r << ") = " << perm << endl;
    }

    void generate_string_permutations() {
        string str;
        cout << "Enter a string to generate all permutations: ";
        cin.ignore(); // clear buffer
        getline(cin, str);

        sort(str.begin(), str.end()); // sort first to start from lexicographical order
        cout << "\nAll permutations of \"" << str << "\":" << endl;

        do {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));
    }
};

class Combination : public Permutations {
public:
    void display() override {
        Permutations::display();
        int comb = factorial(n) / (factorial(r) * factorial(n - r));
        cout << "Combinations C(" << n << ", " << r << ") = " << comb << endl;
    }
};

int main() {
    Combination c;
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Find Permutations and Combinations\n";
        cout << "2. Generate String Permutations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            c.input();
            c.display();
            break;
        case 2:
            c.generate_string_permutations();
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
