/*Create a class TimeCounter to represent a time counter in seconds.
Implement the prefix and postfix increment operators ++ to increase the
time counter by one second. The class provides separate functions for
prefix and postfix increment operations to showcase the difference in
behavior between the operators. The example usage demonstrates the time
counter's functionality with appropriate test cases, displaying the updated
time counter after each increment operation.*/
#include<iostream>
using namespace std;

class TimeCounter {
    int counter;
    int assign;
    public:
    TimeCounter() {
        counter = 0;
        assign = 0;
    }
    TimeCounter(int c) {
        counter = c;
    }
    void operator++() { // pre
        assign = ++counter;
    }
    void operator++(int) { //post
        assign = counter++;
    }
    void display() {
        cout << "Counter: " << counter << endl;
        cout << "Assign Difference: " << assign << endl;
    }
};

int main() {
    TimeCounter t;
    t.display();
    cout << "Prefix operator overloading" << endl;
    ++t;
    t.display();
    cout << "Post operator overloding" << endl;
    t++;
    t.display();
    return 0;
}