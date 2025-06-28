/*You are provided with a Time class that represents time in hours and
minutes. The class has two private member variables: hours (to store the
time in hours) and minutes (to store the time in minutes). Your task is to
implement a member function that allows conversion from Time to int,
representing the total minutes.*/

#include<iostream>
using namespace std;

class Time {
    int hour, min;
    public:
    Time() {
        hour = min = 0;
    }
    int& get_hour() {
        return hour;
    }
    int& get_min() {
        return min;
    }
    int convert() {
        return (hour*60) + min;
    }
};

int main() {
    Time t;
    cout << "Enter the asked info" << endl;
    cout << "Hour: ";
    cin >> t.get_hour();
    cout << "Minute: ";
    cin >> t.get_min();
    int ans = t.convert();
    cout << "After conversion" << endl;
    cout << "In minute: " << ans << endl;
    return 0;
}