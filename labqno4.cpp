/*Write a program to compare magnitude of complex numbers by overloading
<,>,== and != operators*/
#include<iostream>
#include<cmath>
using namespace std;

class Compare {
    int img;
    int real;
    float mag;
    public:
    Compare() {
        real = img = 0;
    }
    
    void input() {
        cout << "Enter the asked info" << endl;
        cout << "Real: ";
        cin >> real;
        cout << "Imaginary: ";
        cin >> img;
        mag = calc_magnitude();
    }
    float calc_magnitude() {
       return sqrt(real*real + img*img);
    }
    bool operator > (const Compare &c) {
        if (mag > c.mag)
        {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator < (const Compare &c) {
        if (mag < c.mag)
        {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator == (const Compare &c) {
        if (mag == c.mag)
        {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator != (const Compare &c) {
        if (mag != c.mag)
        {
            return true;
        }
        else {
            return false;
        }
    }
    float getmag() {
        return mag;
    }

};

int main() {
    Compare c1,c2;
    cout << "This is the program to compare two complex numbers" << endl;
    cout << "Enter first complex number" << endl;
    c1.input();
    cout << "Enter second complex number" << endl;
    c2.input();
    if(c1>c2) {
        cout << "Magnitude of C1 (first complex number) is greater i.e. " << c1.getmag() << endl;
    }
    if(c1<c2) {
        cout << "Magnitude of C2 (second complex number) is greater i.e. " << c2.getmag() << endl;
    }
    if(c1 == c2) {
        cout << "Both Magnitude are equal" << endl;
    }
    if(c1 != c2) {
        cout << "Magnitudes are not equal i.e. " << c1.getmag() << "," << c2.getmag()<< endl;
    }
    return 0;
}