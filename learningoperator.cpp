#include<iostream>
using namespace std;
class learn_operator_overloading {
    int real;
    int img;
    public:
        learn_operator_overloading() {
            real = img = 0;
        }
        learn_operator_overloading(int r, int i): real(r), img(i) {} 
        learn_operator_overloading operator+(const learn_operator_overloading& another) {
            return learn_operator_overloading(real+another.real, img+another.img);
        }
        void display() {
            cout << "(" << real << " + i" << img << ")" << endl;
        }
        void input() {
            cout << "Real Part = ";
            cin >> real;
            cout << "Imaginary Part = ";
            cin >> img;
        }
};
int main() {
    learn_operator_overloading l1, l2, sum;
    cout << "Enter the first complex number" << endl;
    l1.input();
    cout << "Enter the second complex number" << endl;
    l2.input();
    sum = l1+l2;
    cout << "The sum of those complex numbers are " << endl;
    sum.display();
    return 0;
}