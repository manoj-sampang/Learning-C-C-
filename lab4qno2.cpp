/*Write a program to implement Pointer to object and member access.*/
#include<iostream>
using namespace std;

class PointerAccess {
    string name;
    int id;

public:
    PointerAccess() {
        name = "default name";
        id = 0;
    }

    void display() {
        cout << "Name = " << name << "\t ID = " << id << endl;
    }

    void input() {
        cout << "ID = ";
        cin >> id;
        cin.ignore(); // flush leftover newline
        cout << "Name = ";
        getline(cin, name);
    }

    // Public setters and getters (for safe access in Swap)
    void setData(string n, int i) {
        name = n;
        id = i;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }
};

// Swap using pointer to object and -> operator
void swapObjects(PointerAccess* x, PointerAccess* y) {
    string tempName = x->getName();
    int tempId = x->getId();

    x->setData(y->getName(), y->getId());
    y->setData(tempName, tempId);
}

int main() {
    PointerAccess p1, p2;

    cout << "Enter first object as asked (P1)" << endl;
    p1.input();

    cout << "Enter second object as asked (P2)" << endl;
    p2.input();

    cout << "\n------ Before Swapping ------" << endl;
    p1.display();
    p2.display();

    swapObjects(&p1, &p2); // 👈 pass pointer to objects

    cout << "\n------ After Swapping ------" << endl;
    p1.display();
    p2.display();

    return 0;
}
