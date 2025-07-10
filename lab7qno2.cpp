/*Write a program to access the overridden data members and member
functions of question number 2 by the help of a member function of a derived
class and also by the help of a derived class object*/

#include<iostream>
using namespace std;

class Person {
    int age;
    string name;
public:
    virtual void displayInfo() {  //Make virtual to allow overriding
        cout << "Name: " << name << "\tAge: " << age << endl;
    }

    string& get_Name() {
        return name;
    }

    int& get_Age() {
        return age;
    }
};

class Faculty : protected Person {
    string department;
public:
    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
    }

    void input() {
        string temp;
        cout << "Enter Faculty info\n";
        cout << "Name: ";
        getline(cin, temp);
        get_Name() = temp;

        cout << "Age: ";
        cin >> get_Age();
        cin.ignore(); //clear leftover newline

        cout << "Department: ";
        getline(cin, department);
    }

    void accessBaseData() {
        cout << "\nAccessed inside derived class (Faculty):\n";
        displayInfo();
    }
};

class Staff : protected Person {
    string position;
public:
    void displayInfo() {
        Person::displayInfo();
        cout << "Position: " << position << endl;
    }

    void input() {
        string temp;
        cout << "\nEnter Staff info\n";
        cout << "Name: ";
        getline(cin, temp);
        get_Name() = temp;

        cout << "Age: ";
        cin >> get_Age();
        cin.ignore();

        cout << "Position: ";
        getline(cin, position);
    }

    void accessBaseData() {
        cout << "\nAccessed inside derived class (Staff):\n";
        displayInfo();
    }
};

int main() {
    Faculty f;
    Staff s;

    f.input();
    s.input();

    cout << "\n--- Output using derived class objects ---\n";
    f.displayInfo();
    s.displayInfo();

    cout << "\n--- Output using member function inside derived class ---\n";
    f.accessBaseData();
    s.accessBaseData();

    return 0;
}
