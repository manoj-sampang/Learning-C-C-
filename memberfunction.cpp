#include<iostream>
using namespace std;

struct Employee {
    int id;
    char name[50];
    float salary;

    void input() {
        cout << "Enter your id = ";
        cin >> id;
        cin.ignore();  // clear leftover newline

        cout << "Enter name = ";
        cin.getline(name, 50);

        cout << "Enter salary = ";
        cin >> salary;
    }

    void display() {
        cout << "Name = " << name << endl;
        cout << "ID = " << id << endl;
        cout << "Salary = " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees you want to store: ";
    cin >> n;

    Employee *e = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Employee " << i + 1 << " ---" << endl;
        e[i].input();
        e[i].display();
    }

    delete[] e; // cleanup
    return 0;
}
