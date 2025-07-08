/*Write a program to access the overridden data members and member
functions of question number 2 by the help of a member function of a derived
class and also by the help of a derived class object*/

#include<iostream>
using namespace std;

class Person {
    int age;
    string name;
    public:
    void displayInfo() {
        cout << "Name: " << name << "\tAge: " << age << endl;
    }
    string& get_Name() {
        return name;
    }
    int& get_Age() {
        return age;
    }
};

class Faculty:protected Person {
    string department;
    public:
    void displayInfo() {
        Person::displayInfo();
        cout << "Department: " << department << endl;
    }
    void input() {
        cout << "Enter the asked info" << endl;
        cout << "Name: ";
        getline(cin,get_Name());
        cout << "Age: ";
        cin >> get_Age();
        getline(cin, department);
        cin >> department;
    }
};

class Staff:protected Person{
    string position;
    public:
    void displayInfo() {
        Person::displayInfo();
        cout << "Position: " << position << endl;
    }
    void input() {
        cout << "Position: ";
        getline(cin, position);
    }
};

int main() {
    Faculty f;
    Staff s;
    f.input();
    f.displayInfo();
    s.displayInfo();
    return 0;
}
