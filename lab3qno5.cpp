/*WAP to show the destructor call such that it prints the message “memory is
released”.*/
#include<iostream>
using namespace std;
class Destructor{
    public:
    ~Destructor()
    {
        cout<<"-----Destructor Called-----"<<endl;
        cout<<"Memory is released"<<endl;
    }
};
int main()
{
    Destructor d;
    return 0;
}