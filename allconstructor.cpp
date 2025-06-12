//wap to display the hrs, min and sec of the time which is input by the user 
//and also use all the contructor
#include<iostream>
using namespace std;
class Time {
    int hour,min,sec;
    public:
    //default constructor
        Time() {
            hour = min = sec = 0;
        }
        //parametrized constructor 
        Time(int h, int m, int s) {
            hour = h;
            min = m;
            sec = s;
        }
        //Copy constructor 
        Time(Time &c) {
            hour = c.hour;
            min = c.min;
            sec = c.sec;
        }
        void display() {
            cout << hour << "hrs " << min << "mins " << sec << "secs" << endl;
        }


    ~Time() {
        cout << "Destructor Called" << endl;
    }
};
int main() {
    int hr,mi,se;
    Time t1;
    t1.display();
    cout << "Enter any the asked info" << endl;
    cout << "hour = ";
    cin >> hr;
    cout << "Min = ";
    cin >> mi;
    cout << "Sec = ";
    cin >> se;
    Time t2(hr,mi,se);
    t2.display();
    Time t3 = t2;
    t3.display();
    return 0;
}
