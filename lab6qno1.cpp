/*You are provided with a Height class that represents a person's height in
the feet-inch system. The class has two private member variables: feet (to
store the height in feet) and inches (to store the height in inches). Your task
is to implement a constructor that allows conversion from int (representing
height in inches) to Height. Try to implement given conversion using
explicit constructor.*/

#include<iostream>
using namespace std;
class Height {
    int inch, feet;
    public:
    Height() {
        inch = feet = 0;
    }
    Height(int i) {
        feet = i/12;
        inch = i%12;
    }
    void display() {
        cout << "Ans: " << feet << "feet " << inch <<"inch."<<endl;
    }

};
int main() {
    Height h;
    int i;
    cout << "Enter inch measurement for feet-inch convertor" << endl;
    cout << "Inch = ";
    cin >> i;
    h = i;
    h.display();
    return 0;
}