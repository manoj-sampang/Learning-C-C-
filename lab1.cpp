/*create basic data types like float, int, double, char, string, and char of string which the 
user inputs from the keyboard*/
#include<iostream>
using namespace std;
int main()
{
    int i_num,choice;
    float f_num;
    double d_num;
    char c_num;
    string sochar;
    char cos[50];
    cout<<"Enter specific data"<<endl;
    cout<<"Integer = ";cin>>i_num;
    cout<<"Float Number = ";cin>>f_num;
    cout<<"Double Number = ";cin>>d_num;
    cout<<"Enter a character = ";
    cin>>c_num;
    cin.ignore();
    cout<<"Enter a message = ";getline(cin,sochar);
    cout<<"Character of string = ";cin.getline(cos,50);
    cout<<"Choose what to display";
    while(1){
        cout<<"\n1. Integer\n2. Float\n3. Double Number\n3. Double\n4. Character\n5. Message\n6. Character of string\n7.Exit"<<endl;
        cout<<"Choose (1-6) = ";cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"Ouput = "<<i_num;
            break;
        case 2:
            cout<<"Ouput = "<<f_num;
            break;
        case 3:
            cout<<"Ouput = "<<d_num;
            break;
        case 4:
            cout<<"Ouput = "<<c_num;
            break;
        case 5:
            cout<<"Ouput = "<<sochar;
            break;
        case 6:
            cout<<"Ouput = "<<cos;
            break;
        case 7:
            return 0;
        default:
            cout<<"Invalid input Try again!!!"<<endl;
    } 
}

}