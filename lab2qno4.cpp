/*WAP to implement return by reference.*/
#include<iostream>
using namespace std;

float& return_by_refernce(float& a, float& b);

float& return_by_refernce(float& a, float& b) { 
    if(a > b)
    {
        return a;
    }
    else {
        return b;
    }
}

int main()
{
    float num1, num2;
    
    cout << "Implementing Return by Refernce\n" << endl;
    cout << "Enter number 1 = ";
    cin >> num1;
    cout << "Enter number 2 = ";
    cin >> num2;
    float& bigger = return_by_refernce(num1,num2); //return reference to the bigger which is also a reference variable
    cout << "--------Before Reference Example---------" << endl;
    cout << "num1 = " << num1 << "\t num2 = " << num2 << endl;
    cout << "Greater = " << bigger << endl;
    cout << "If I give something like Greater = 100 then see the ouput of the numbers" <<endl;
    bigger = 100;
    cout << "--------After Reference Example---------" << endl;
    cout << "num1 = " << num1 << "\t num2 = " << num2 << endl;
    cout << "Greater = " << bigger << endl;
    return 0;
}
