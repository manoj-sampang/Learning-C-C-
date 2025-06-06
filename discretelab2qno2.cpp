//floor and ceiling value
// x = 5.5 floor value = 5 and ceiling value is 6
// x = 5 floor value = 5 and ceiling value is 5
// x = 4.3 floor value = 4 and ceiling value is 5;
#include<iostream>
using namespace std;
class num_check
{
    float num;
    public:
    num_check(float default_num = 5.53)
    {
        num = default_num;
    }
    void ceil()
    {
        cout<<"Ceiling Value = ";
        if(num<0)
        {
            cout<<int(num);
        }
        if(num == int(num))
        {
            cout<<num;
        }
        if(num>0)
        {
            cout<<int(num)+1;
        }
    }
    void floor()
    {
        cout<<"Floor Value = ";
        if(num<0)
        {
            cout<<int(num)-1;
        }
        if(num == int(num))
        {
            cout<<num;
        }
        if(num>0)
        {
            cout<<int(num);
        }
    }
};
int main()
{
    float num;
    int choice;
    cout<<"Enter the number to check its floor value and ceiling value\n";
    if(!(cin>>num))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    num_check n_c(num);
    while(1)
    {
        cout<<"\nEnter your choice"<<endl;
        cout<<"1. Floor Value\n2. Ceiling Value\n3. Quit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                n_c.floor();
                break;
            case 2:
                n_c.ceil();
                break;
            case 3:
                return 0;
            default:
                cout<<"Invalid Number!!!Please Try again"<<endl;
        }
    }
    return 0;
}