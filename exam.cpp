#include<iostream>
using namespace std;

//operator overloading
class Operator {
    double x, y;
    public:
        Operator() : x(0) , y(0) {}
        Operator(double x1, double y1) : x(x1), y(y1) {}
        
        Operator& operator ++() {   //prefix increment
            Operator temp;
            ++x; ++y;
            return temp;=
        } 
        void operator ++(int); //postfix increment
        void display();


        double get_x() {
            return x;
        }
        double get_y() {
            return y;
        }
};

void Operator::display() {
    cout << "X = " << x << "\tY = " << y << endl;
}


int main() {
    Operator O;
    cout << "This programs demonstrates Postfix and Prefix operator overloading." << endl;
    cout << "Initial Values" << endl;
    cout << "X = " << O.get_x() << "\tY = " << O.get_y() << endl;
    cout << " --- Prefix overloading --- " << endl;
    ++O;
    O.display();
    cout << " --- Postfix overloading --- " << endl;
    O++;
    O.display();
    return 0;
}