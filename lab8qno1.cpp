/*Create a base class Employee with a member name and a function display()
to print the name. Derive a class Manager from Employee that adds a member
department and overrides the display() function to print both name and
department. In main()function create a Manager object, assign its address to
a Employee* pointer. Set the name using the base class pointer. Try setting
the department using the base class pointer and observe what happens. Call
the display() function using both base and derived class pointers.
i. Explain why department cannot be accessed through the base class
pointer.
ii. What happens if display() is not declared as virtual in the base class?*/

#include <iostream>
using namespace std;

class Employee {
    string name;
    public:
        virtual void display() {
            cout << "Name: " << name << endl;
        }
        string& getName() {
            return name;
        }
};


class Manager : public Employee {
    string department;
    public:
    void input() {
        string temp;
        cout << "Enter the asked info" << endl;
        cout << "Name: ";
        getline(cin, temp);
        Employee::getName() = temp;
        cout << "Department: ";
        getline(cin, department);
    }
        void display() {
            Employee::display(); // access inside base class
            cout << "Department: " << department << endl;
        }
};

int main() {
    Manager M;
    M.input();
    cout << "Without assigning the address of Manager object" << endl;
    M.display();
    Employee *E;
    E = &M;
    cout << "After assigning the address of Manager object" << endl;
    E->display();
    return 0;
}
