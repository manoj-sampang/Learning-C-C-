#include <iostream>
using namespace std;

class Time {
    int hour;
    int min;
    int sec;

public:
    // Default constructor
    Time() {
        hour = 0;
        min = 0;
        sec = 0;
    }

    // Parameterized constructor 
    Time(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
        normalize(); 
    }

    // Input function
    void input() {
        cout << "Hour = ";
        cin >> hour;
        cout << "Minute = ";
        cin >> min;
        cout << "Second = ";
        cin >> sec;
    }

    // Display function
    void display() {
        cout << "Time = " << hour << " hrs " << min << " mins " << sec << " secs" << endl;
    }

    // Normalize time
    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec %= 60;
        }
        if (min >= 60) {
            hour += min / 60;
            min %= 60;
        }
    }

    // Operator overloading for +
    Time operator+(Time t) {
        Time temp;
        temp.hour = hour + t.hour;
        temp.min = min + t.min;
        temp.sec = sec + t.sec;
        temp.normalize();
        return temp;
    }
};

int main() {
    Time t1, t2, sum;

    cout << "Enter first time:\n";
    t1.input();

    cout << "Enter second time:\n";
    t2.input();

    sum = t1 + t2;

    cout << "\n--- Sum of Times ---\n";
    sum.display();

    return 0;
}
