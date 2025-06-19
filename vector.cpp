#include<iostream>
#include<vector>
using namespace std;

class Vector {
    vector<int> y;
    vector<int> x;
public:
    Vector() : y(5, 30), x(y) {} 
    void display() {
        for (int n : x) cout << n << " ";
        for (int n : y) cout << n << " ";
    }
};


int main() {
    Vector v;
    v.display();
    return 0;
}