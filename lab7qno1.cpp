/*Create a C++ program involving classes Person, Faculty, and Staff. The base
class Person contains private attributes name and age. The derived Faculty
class adds a protected attribute department and overrides displayInfo() to
include name, age, and department. Similarly, the derived Staff class adds a
protected attribute position and overrides displayInfo() with name, age, and
position.Write a program that creates instances of Faculty and Staff, sets their
attributes and calls displayInfo() for both instances. Observe data member
and member function overriding during compilation and execution.*/

#include<iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void displayInfo() {
        cout << "Name: " << name << "\tAge: " << age << endl;
    }
};

class Faculty : public Person {
    string department;
public:
    Faculty(string n, int a, string d) : Person(n, a), department(d) {}

    //Override displayInfo
    void displayInfo() {
        cout << "Name: " << name << "\tAge: " << age << "\tDepartment: " << department << endl;
    }
};

class Staff : public Person {
    string position;
public:
    Staff(string n, int a, string p) : Person(n, a), position(p) {}

    //Override displayInfo
    void displayInfo() {
        cout << "Name: " << name << "\tAge: " << age << "\tPosition: " << position << endl;
    }
};

int main() {
    Faculty f("Hari", 40, "Computer Science");
    Staff s("Ram", 35, "Bsc. Csit");

    f.displayInfo();
    s.displayInfo();

    return 0;
}
