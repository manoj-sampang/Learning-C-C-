/*⁠WAP to find the volume of a cube, cuboid and cylinder using the concept of
function overloading.*/
#include<iostream>
#define PI 3.1415
using namespace std;
inline evoid volume(float l,float b)
{
    cout<<"Volume of Cube is = "<<l*b<<endl;
}
inline void volume(float l, float b, float h)
{
    cout<<"Volume of Cubiod is = "<<l*b*h<<endl;
}
inline void volume(float r)
{
    cout<<"Volume of Cylinder is = "<<4/3*PI*r*r*r<<endl;
}
int main()
{   
    int choice,a,b,c,h;
    cout<<"Enter the data as told for Volume of objects"<<endl;
    cout<<"Length = ";
    cin>>a;
    cout<<"Breadth = ";
    cin>>b;
    cout<<"Radius = ";
    cin>>c;
    cout<<"Height = ";
    cin>>h;
    cout<<"What to do with the data\n";
    cout<<"1. Volume of Cube\n2. Volume of Cuboid\n3. Volume of Cylinder"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            volume(a,a);
            break;
        case 2:
            volume(a,b,h);
            break;
        case 3:
            volume(c);
            break;
        default:
            cout<<"Invalid Number!!! Failed input"<<endl;
    }
    return 0;
}

