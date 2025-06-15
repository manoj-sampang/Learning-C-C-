//Write a program to test the validity of given argument using the truth table 
#include<iostream>
using namespace std;
class truth_table{
    public:
        int conjunction(int x, int y) {
            return x && y;
        }
        int implication(int x, int y) {
            return !x || y;
        }
        void table_sample() {
            cout << "p\tq\tp->q\tpv(p->q)\t(pv(p->q))->q" << endl;
            for(int i = 0; i <= 1; ++i) {
                for(int j = 0; j <= 1; ++j) {
                    cout << i << "\t" << j << "\t " << implication(i,j) << "\t    " << conjunction(i,implication(i,j)) << "\t\t     "
                         << implication(conjunction(i,implication(i,j)),j) << endl;
                }
            }
        }
};
int main() {
    truth_table t;
    t.table_sample();
    cout << "Hence the given arguement is a valid because all the values are true for all condition" << endl;
    cout << "So the following given arguements proved to be a tautology" << endl;
    return 0;
}