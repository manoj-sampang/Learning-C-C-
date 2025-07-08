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

class Staff;
class Faculty;
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
        Staff::input();
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
