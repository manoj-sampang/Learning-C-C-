#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    int* p = &a; // holds the address of a and also could be deference by *p
    int** pp = &p; // holds the address of the pointer p could be dereference value of p and a by *pp and **pp
    cout << p << endl; // so this gives the address of a
    cout << &a <<endl; // this gives also address of a 
    cout << *pp <<endl; // this gives value of p which is address of a
    cout << pp <<endl; // this gives the address of pointer p 
    cout << ** pp << endl; // this gives the value of a that p points to
    return 0;
}