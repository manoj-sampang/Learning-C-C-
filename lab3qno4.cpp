/*Write a C++ program that defines a class called "Rectangle" with private
member variables "length" and "width". The class should have the following
member functions:
i. A default constructor that initializes both "length" and "width" to 0.
ii. A parameterized constructor that takes two arguments and initializes
"length" and "width" accordingly.
iii. A function called "calculateArea" that calculates and returns the area of
the rectangle.
iv. A function called "doubleSize" that takes a Rectangle object as an
argument, doubles its length and width, and returns the modified object.
In the main function, create a Rectangle object using the parameterized
constructor with the values 4 and 5. Then, pass this object to the "doubleSize"
function, and display the area of the modified rectangle.*/
#include<iostream>
using namespace std;
class Rectangle{
    float length;
    float width;
    public:
        Rectangle()
        {
            length = width = 0;
        }
        Rectangle(int l, int w)
        {
            length = l;
            width = w;
        }
        Rectangle doubleSize(Rectangle r)
        {
            Rectangle temp;
            temp.length = 2 * r.length;
            temp.width = 2 * r.width;
            return temp;
        }
        void calc_area();

};
void Rectangle::calc_area()
{
    cout<<"\n----Area Calculated----"<<endl;
    cout<<"The Area of the rectange is = "<<length*width<<endl;
}
int main()
{
    Rectangle r1(4,5);
    Rectangle r2;
    r2 = r2.doubleSize(r1);
    r2.calc_area();
    return 0;
}