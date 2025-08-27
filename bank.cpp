#include<iostream>
#include<vector>

using namespace std;

class CreateAccount {
    string accountName, accountNumber;
    double balance;
    public:
        CreateAccount() : accountName("unknown") , accountNumber("unknown") , balance(0.0) {}
        CreateAccount(string name, string num, double bal) : accountName(name), accountNumber(num), balance(bal) {}

        double getBalance() {
            return balance;
        }
        
        void prompt() {
            string name, num;
            double bal;
            cout << "Enter Account Name: ";
            getline(cin, name);
            cout << "Enter Account Number: ";
            getline(cin, num);
            cout << "Enter Initial Deposit: ";
            cin >> bal;
            cin.ignore();
            accountName = name;
            accountNumber = num;
            balance = bal;
        }

    double deposit(double depo) {
        balance += depo;
        return balance;
    }
    bool withdraw(double with) {
        if(balance >= with) {
            balance -= with;
            return true;
        }
        else {
            return false;
        }
    }
    
        
};

int main() {
    CreateAccount c;
    c.prompt();
    if(c.deposit(5000.00)) {
        cout << "Successfully Desposited" << endl;
        cout << "Current Balance: " << c.getBalance() << endl;
    }
    if(c.withdraw(5000543)) {
        cout << "Successfully Withdrawn" << endl;
        cout << "Current Balance " << c.getBalance() << endl;
    }
    else {
        cout << "Error Due to Insufficient Balance!!!" << endl;
    }
    
    

    return 0;
}

