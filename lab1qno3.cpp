 /*⁠Implement a C++ program that demonstrates the usage of namespaces. Create
three namespaces called "English","Nepali" and “Newa”. All namespaces
should define a function called "greet" that takes no parameters and returns a
greeting message in the respective language. In the main function, invoke the
"greet" function from each namespace and display the greetings.*/
#include<iostream>
using namespace std;
namespace English{
    string greet(){
        string ans;
        ans = "Hello, How are you doing today!";
        return ans;
    }
}
namespace Nepali{
    string greet(){
        string ans;
        ans = "Namaste!!";
        return ans;
    }
}
namespace Newa{
    string greet(){
        string ans;
        ans = "Jwalapa!!";
        return ans;
    }
}
int main(){
    int choice;
    string greet_message;
    cout<<"Pick a language for greeting"<<endl;
    cout<<"\nChoose either \n1. English\n2. Nepali\n3. Newari\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
            greet_message = English::greet();
            cout<<greet_message;
            break;
        case 2:
            greet_message = Nepali::greet();
            cout<<greet_message;
            break;
        case 3:
            greet_message = Newa::greet();
            cout<<greet_message;
            break;
        default:
            cout<<"Invalid number!!! Please try again";
    }
    return 0;
}