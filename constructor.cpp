//use all constructor;

#include<iostream>
using namespace std;
class Time{
int member[3];
public:
    Time()//default constructor
    {
        cout<<"Deafult constructor called!!!"<<endl;
        for(int i=0;i<3;i++){
            member[i] = 0;
        }
    }
    Time(int h, int m, int s)//paramatric constructor
    {
        cout<<"Parametric constructor called!!!"<<endl;
        member[0] = h;
        member[1] = m;
        member[2] = s;
        
    }
    Time(Time &copy){
        cout<<"Copy constructor called!!!"<<endl;
        member[0] = t1.member[0];
        
    }
    void display(){
        cout<<"The time you input is formatted in the given form"<<endl;
        for(int i=0;i<3;i++){
            if(member[i]<=9){
                cout<<"0"<<member[i];
            }
            else{
                cout<<member[i];
            }
            if(i<2){
                cout<<":";
            }
        }
    }
};
int main(){
    Time t;
    Time t1(2,3,10);
    Time t2 = t1;
    t.display();
    t1.display();
    t2.display();
    return 0;
}
