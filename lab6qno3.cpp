/*Create a class Journey with two private data members: distanceInMeters
(of type double) and timeInSeconds (of type double). Also, create another
class Speed with two private data members: metersPerSecond (of type
double) and kilometersPerHour (of type double).You are required to
implement two different approaches to convert an object of type Journey
into an object of type Speed:
i. Using a One-Argument Parameterized Constructor
ii. Using a Casting Operator Function
Demonstrate both conversions in the main() function.
metersPerSecond=!"#$%&'()&*($(+#
$",()&-('.&!#

kilometersPerHour=metersPerSecond×3.6*/

#include<iostream>
using namespace std;

class Journey {
    double distanceInMeters, timeInSeconds;
    public:
    Journey() {
        distanceInMeters = timeInSeconds = 0.0;
    }
    double get_distance() {
        return distanceInMeters;
    }
    double get_time() {
        return timeInSeconds;
    }
    void input() {
        cout << "Enter the asked info" << endl;
        cout << "Distance (in meter): ";
        cin >> distanceInMeters;
        cout << "Time (in seconds): ";
        cin >> timeInSeconds;
    }
};
class Speed {
    double metersPerSecond, kilometersPerHour;
    public:
    Speed() {
        metersPerSecond = kilometersPerHour = 0.0;
    }
    Speed(Journey j) {
        metersPerSecond = j.get_distance()/j.get_time();
        kilometersPerHour = metersPerSecond*3.6;
    }
    void display() {
        cout << "Ans: " << metersPerSecond << "m/s" << endl;
        cout << "Ans: " << kilometersPerHour << "km/hr" << endl;
    }
};
int main() {
    Journey j1;
    j1.input();
    Speed s1 = j1;
    cout << "Calculating......" << endl;
    s1.display();
    cout << "Velocities both in m/s and km/hr" << endl;
    return 0;
}