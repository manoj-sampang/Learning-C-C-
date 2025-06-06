#include<iostream>
using namespace std;

class Time {
    int hour;
    int min; 
    int sec;

public:
    Time() {
        hour = min = sec = 0;
    }

    Time(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
        normalize(); // always store normalized time
    }

    // Addition
    Time tAdd(Time x, Time y) {
        int h = x.hour + y.hour;
        int m = x.min + y.min;
        int s = x.sec + y.sec;
        return Time(h, m, s);  // Nameless temporary object returned
    }

    // Subtraction
    Time tSub(Time x, Time y) {
        int h = x.hour - y.hour;
        int m = x.min - y.min;
        int s = x.sec - y.sec;
        return Time(h, m, s);  // Nameless temporary object returned
    }

    // Normalize time (used internally)
    void normalize() {
        if (sec >= 60) {
            min += sec / 60;
            sec = sec % 60;
        } else if (sec < 0) {
            int borrow = (abs(sec) + 59) / 60;
            min -= borrow;
            sec += borrow * 60;
        }

        if (min >= 60) {
            hour += min / 60;
            min = min % 60;
        } else if (min < 0) {
            int borrow = (abs(min) + 59) / 60;
            hour -= borrow;
            min += borrow * 60;
        }
    }

    void input() {
        cout << "Hour = ";
        cin >> hour;
        cout << "Minute = ";
        cin >> min;
        cout << "Second = ";
        cin >> sec; 
        normalize();  // Normalize on input
    }

    void display() {
        cout << "\nTime: " << hour << " hrs " << min << " min " << sec << " sec\n";
    }
};

int main() {
    Time t1, t2, sum, sub;

    cout << "Enter first time:\n";
    t1.input();
    cout << "Enter second time:\n";
    t2.input();

    // Use nameless temporary object explicitly
    sum = sum.tAdd(t1, t2);  // `Time()` is a nameless temporary object
    sub = sub.tSub(t1, t2);  // same here

    cout << "\n--- Result ---\n";
    cout << "Sum:";
    sum.display();
    cout << "Difference:";
    sub.display();

    return 0;
}
