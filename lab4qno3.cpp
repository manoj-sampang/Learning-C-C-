/*member functions read and display the dimensions of a rectangle. Implement the
following functionalities:
i. Dynamically create a single Rectangle object, read and display the dimensions of
the rectangle object.
ii. Dynamically create an array of Rectangle objects, read and display the dimensions
of each rectangle in the array.*/
#include<iostream>
using namespace std;
class Rectangle {
    float x_dim;
    float y_dim;
    public:
        Rectangle() {
            x_dim = y_dim = 0;
        }
        void read() {
            cout << "Reading the dimension" << endl;
            cout << "x-dimension = ";
            cin >> x_dim;
            cout << "y-dimension = ";
            cin >> y_dim;
        }
        void display() {
            cout << x_dim <<"x" << y_dim <<"in cm" << endl;
        }
};
int main() {
    int num;
    cout << "Enter how many objects you want to allocated:" << endl;
    cout << "num = ";
    cin >> num;
    Rectangle* dma = new Rectangle[num]; // allocates objects as dma
    for(int i = 0; i < num; i++) {
        dma[i].read();
    }
    cout << "Displaying the dimensions" << endl;
    for(int i = 0; i < num; i++) {
        dma[i].display();
    }
    delete[] dma;
    return 0;
}