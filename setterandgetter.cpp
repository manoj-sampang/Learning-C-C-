#include <iostream>
using namespace std;

class learn_getter_and_setter {
    int* ptr1;
    int* ptr2;
    int size1;
    int size2;

public:
    // Default constructor
    learn_getter_and_setter() {
        ptr1 = nullptr;
        ptr2 = nullptr;
        size1 = 0;
        size2 = 0;
    }

    // Input function to dynamically allocate and fill arrays
    void input() {
        cout << "Enter the size of array A: ";
        cin >> size1;
        ptr1 = new int[size1];
        for (int i = 0; i < size1; ++i) {
            cout << "A[" << i + 1 << "] = ";
            cin >> ptr1[i];
        }

        cout << "Enter the size of array B: ";
        cin >> size2;
        ptr2 = new int[size2];
        for (int i = 0; i < size2; ++i) {
            cout << "B[" << i + 1 << "] = ";
            cin >> ptr2[i];
        }
    }

    // Display the arrays
    void display() {
        cout << "\n--- Array A ---\n";
        for (int i = 0; i < size1; ++i) {
            cout << "A[" << i + 1 << "] = " << ptr1[i] << endl;
        }

        cout << "\n--- Array B ---\n";
        for (int i = 0; i < size2; ++i) {
            cout << "B[" << i + 1 << "] = " << ptr2[i] << endl;
        }
    }

    // Example of a getter
    int getFirstA() {
        return ptr1 ? ptr1[0] : 0;
    }

    // Example setter operation: add A and B into A (if sizes match)
    void addArrays() {
        if (size1 != size2) {
            cout << "Cannot add arrays of different sizes!" << endl;
            return;
        }

        for (int i = 0; i < size1; ++i) {
            ptr1[i] += ptr2[i];
        }

        cout << "Arrays added. Updated A[]: \n";
        for (int i = 0; i < size1; ++i) {
            cout << "A[" << i + 1 << "] = " << ptr1[i] << endl;
        }
    }

    // Destructor to free memory
    ~learn_getter_and_setter() {
        delete[] ptr1;
        delete[] ptr2;
        cout << "\nDestructor called. Memory released.\n";
    }
};

int main() {
    learn_getter_and_setter obj;
    obj.input();
    obj.display();

    cout << "\nCalling addArrays()...\n";
    obj.addArrays();

    cout << "\nFirst element of A using getter: " << obj.getFirstA() << endl;

    return 0;
}
