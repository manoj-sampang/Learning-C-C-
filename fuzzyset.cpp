//lab 3 of discrete 
#include<iostream>
using namespace std;
class fuzzy_set{
    float num1;
    float num2;
    public:
    fuzzy_set(float a, float b)
    {
        num1 = a;
        num2 = b;
    }
        void f_union()
        {  
            if(num1>num2)
            {
                cout<<"FUZZY UNION = "<<num1<<endl;
            }
            else{
                cout<<"FUZZY UNION = "<<num2<<endl;
            }
        }
        void f_intersection()
        {
            if(num1>num2)
            {
                cout<<"FUZZY INTERSECTION = "<<num2<<endl;
            }
            else{
                cout<<"FUZZY INTERSECTION = "<<num1<<endl;
            }
        }
        void f_complement()
        {
            int choose;
            cout<<"Choose either"<<endl;
            cout<<"1. A' (A complement)\n"
                <<"2. B' (B complement)\n";
            cout<<"Choose(1-2) = ";
            cin>>choose;
            switch(choose)
        {
            case 1:
                cout<<"A' = "<<1-num1<<endl;
                break;
            case 2:
                cout<<"B' = "<<1-num2<<endl;
                break;
            default:
                cout<<"Invalid number\n!!Please try again"<<endl;
        }
        }
};
int main()
{
    float n1,n2;
    int choice;
    while(1){cout<<"Enter the element of the fuzzy set"<<endl;
    again: cout<<"NOTE: Fuzzy set is a measure of degree which ranges from (0-1) including 0 and 1 too"<<endl;
    cout<<"A = ";
    cin>>n1;
    if(n1<0 || n1>1)
    {
        cout<<"Invalid input enter again!!"<<endl;
        goto again;
    }
    b_again: cout<<"B = ";
    cin>>n2;
    if(n2<0 || n2>1)
    {
        cout<<"Invalid input enter again!!"<<endl;;
        goto b_again;
    }
    fuzzy_set f(n1,n2);
    while(1){cout<<"Choose the method"<<endl;
    cout<<"1. Union"<<endl;
    cout<<"2. Intersection"<<endl;
    cout<<"3. Complement"<<endl;
    cout<<"4. Restart"<<endl;
    cout<<"5. Quit"<<endl;
    cout<<"Choose(1-5) = ";
    cin>>choice;
    cin.ignore();
    switch(choice)
    {
        case 1:
            f.f_union();
            break;
        case 2:
            f.f_intersection();
            break;
        case 3:
            f.f_complement();
            break;
        case 4:
            goto restart;
        case 5:
            return 0;
        default:
            cout<<"Invalid Input!!Please try again"<<endl;
    }
}
restart:;
}
}