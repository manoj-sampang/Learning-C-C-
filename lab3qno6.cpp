#include<iostream>
using namespace std;

class Student {
    string name;
    int age;

public:
    Student() {
        name = "Default Name";
        age = 0;
    }

    void input() {
        cout << "Enter Name: ";
        cin.ignore(); // Clear newline from buffer
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    int getAge() const {
        return age;
    }

    string getName() const {
        return name;
    }
};

float calculateAverage(Student* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i].getAge();
    }
    return static_cast<float>(sum) / n;
}

Student findOldest(Student* arr, int n) {
    Student oldest = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i].getAge() > oldest.getAge()) {
            oldest = arr[i];
        }
    }
    return oldest;
}

int main() {
    int num;
    cout << "Enter the number of students: ";
    cin >> num;

    Student* students = new Student[num];

    for (int i = 0; i < num; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].input();
    }

    float avgAge = calculateAverage(students, num);
    Student oldest = findOldest(students, num);

    cout << "\nAverage Age of Students: " << avgAge << endl;
    cout << "Oldest Student: " << oldest.getName() << " (" << oldest.getAge() << " years old)" << endl;

    delete[] students;
    return 0;
}
