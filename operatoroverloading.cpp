#include<iostream>
using namespace std;

class Time {
    int hour, min, sec;
    public: 
        Time() {
            hour = 0;
            min = 0;
            sec = 0;
        }
        Time(int h, int m, int s) {
            hour = h;
            min = m; 
            sec = s;
            normalize();
        }
        void normalize() {
            if(sec >= 60) {
                min += sec/60;
                sec %= 60;
            }
            if(min >= 60) {
                hour += min/60;
                min %= 60;
            }
        }
        void input() {
            cout << "Enter the hour min and sec as asked" << endl;
            cout << "Hour = "; 
            cin >> hour;
            cout << "Minute = ";
            cin >> min;
            cout << "Seccond = ";
            cin >> sec;
        }
        Time operator+ (Time t) {
            return Time(hour + t.hour, min + t.min, sec + t.sec);  // nameless 
        }
        void display() {
            cout << hour << "hrs\t" << min << "min\t" << sec << "secs" << endl;
        }

};
int main() {
    Time t1, t2;
    cout << "Enter First Time" << endl;
    t1.input();
    cout << "Enter Second Time" << endl;
    t2.input();
    Time sum = t1 + t2;
    sum.display();
    return 0;
}