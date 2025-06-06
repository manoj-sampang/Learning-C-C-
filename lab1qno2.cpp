 /*⁠Implement a macro in C++ called "SQUARE" that takes an argument and
returns the square of that number. Use macro expansion techniques to
compute the square value without using any built-in mathematical functions.*/
#include<iostream>
using namespace std;
inline float SQUARE(float x){
    return x*x;
}
int main()
{
    float num;
    float ans;
    cout<<"Give a number to square = ";
    cin>>num;
    ans = SQUARE(num);
    cout<<"The Square of the number "<<num<<" is "<<ans<<endl;
    return 0;
}
   