//write a menu driven program to show tautology or contradiction  lab 5 Tautology((p^q) -> (pvq))  for Contradiction((pvq)^(~p^~q)) 
#include<iostream>
using namespace std;
class Truth_Table {
    public:
    void Tautology() {
        cout << "-------TAUTOLOGY---------\n";
        cout << "p\tq\t(p^q)\t(pvq)\t((p^q)->(pvq))\n";
        for(int i = 0; i <=1; i++) {
            for (int j = 0; j <=1; ++j) {
                cout << i <<"\t" << j << "\t  " << Conjunction(i,j) <<"\t  " << Disjunction(i,j) << "\t\t" << Implication(Conjunction(i,j),Disjunction(i,j))<<"\n";
            }
        }
    }
    void Contradiction() {
        cout << "-------CONTRADICTION---------\n";
        cout << "p\tq\t(pvq)\t(~p^~q)\t((pvq)^(~p^~q))\n";
        for(int i = 0; i <=1; i++) {
            for (int j = 0; j <=1; ++j) {
                cout << i <<"\t" << j <<"\t  " << Disjunction(i,j) <<"\t   " << Conjunction(Negation(i),Negation(j)) << "\t\t" << Conjunction(Disjunction(i,j),Conjunction(Negation(i),Negation(j)))<<"\n";
            }
        }
    }
    int Conjunction(int p, int q) {
        return p && q;
    }
    int Implication(int p, int q) {
        return (!p) || q;
    }
    int Disjunction(int p, int q) {
        return p || q;
    }
    int Negation(int p) {
        return !p;
    }

};
int main () {
    int choice;
    Truth_Table t;
    while(true) {
        cout << "This is a menu-driven program to show Contradiction and Tautology\n" << endl;
        cout << "1. Tautology\n"
             << "2. Contradiction\n"
             << "3. Quit" << endl;
        cout << "Choose(1-3): ";
        cin >> choice;
        switch(choice) {
            case 1: 
                t.Tautology();
                break;
            case 2:
                t.Contradiction();
                break;
            case 3:
                cout << "Quiting.........\n" << endl;
                return 0;
            default: 
                cout << "--INVALID INPUT--TRY AGAIN" << endl;
        }
    } 
}