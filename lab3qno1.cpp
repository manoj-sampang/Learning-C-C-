#include <iostream>
using namespace std;

class Teacher {
    int t_id;
    string t_name;
    string t_depart;
    string t_subject;

public:
    // Constructor
    Teacher() {
        t_id = 0;
        t_name = t_depart = t_subject = "";
    }

    // Read data from user
    void read() {
        cout << "\n-------Enter Teacher Information-------\n";
        cout << "Teacher ID = ";
        cin >> t_id;
        cin.ignore();  // Clear newline left in buffer

        cout << "Teacher name = ";
        getline(cin, t_name);

        cout << "Teacher Department = ";
        getline(cin, t_depart);

        cout << "Subject Taught = ";
        getline(cin, t_subject);
    }

    // Display teacher information
    void display() const;
};

// Member function defined outside the class
void Teacher::display() const {
    cout << "\n------Teacher's Information-------\n";
    cout << "Teacher ID       = " << t_id << endl;
    cout << "Teacher Name     = " << t_name << endl;
    cout << "Department       = " << t_depart << endl;
    cout << "Subject Taught   = " << t_subject << endl;
}

int main() {
    int n;
    cout << "Enter the number of Teachers: ";
    cin >> n;

    Teacher* t1 = new Teacher[n];  // dynamically allocated array

    // Input Phase
    for (int i = 0; i < n; i++) {
        cout << "\nTeacher #" << (i + 1);
        t1[i].read();
    }

    // Output Phase
    for (int i = 0; i < n; i++) {
        cout << "\nDisplaying Teacher #" << (i + 1);
        t1[i].display();
    }

    delete[] t1;  // Free dynamically allocated memory
    return 0;
}
