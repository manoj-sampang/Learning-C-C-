#include<iostream>
#include<iomanip>
using namespace std;
class Function{
    private:
    double num;
    public:
    void floor_func(double n){
        num = int(n);
        if(n>=0){
        cout<<"Floor function = "<<num<<endl;
        }
        else{
            cout<<"Floor function = "<<num-1<<endl;
        }
    }
    void ceiling_func(double n){
        num = int(n);
        if(num>=0){
        cout<<"Ceiling function = "<<num+1<<endl;
        }
        else{
            cout<<"Ceiling function = "<<num<<endl;
        }
    }
};