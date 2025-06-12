#include<iostream>
using namespace std;
class Number{
    int num1, num2;
    public: 
        Number() {
            num1 = num2 = 0;
        }
        Number(int number1, int number2) {
            num1 = number1;
            num2 = number2;
        }
        Number(Number const &x) {
            num1 = x.num1; //same as n2.num1
            //x.num1 = n2.num1;
            //x.num2 = n2.num2;
            num2 = x.num2;

        }
    void input() { 
        cout << "Enter number" << endl;
        cout << "Num1 = ";
        cin >> num1;
        cout << "Num2 = ";
        cin >>num2;
    }
        void display() {
            cout << num1 <<"\t" << num2 << endl;
        }
};
int main() {
    Number n1;
    Number n2(2,5);
    Number n3(n2);
    n3.display();
    n2.display();
    n1.display();
    return 0;
}