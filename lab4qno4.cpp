/*Define a class called BankAccount with private member variables accountNumber,
balance, and a static member variable totalAccounts to keep track of the total number
of bank accounts created. Implement the following functionalities:
i. A constructor that initializes the accountNumber and balance variables and
increments the totalAccounts count.
ii. A member function deposit() that takes an amount as input and adds it to the balance
of the account.
iii. A member function withdraw() that takes an amount as input and subtracts it from
the balance, only if the balance is sufficient.
iv. A static member function getTotalAccounts() that returns the total number of bank
accounts created.*/
#include<iostream>
using namespace std;

class BankAccount {
    int accountNumber;
    float balance;
    static int totalAccounts; //Declaration only here

public:
    BankAccount() {
        accountNumber = 0;
        balance = 0;
        totalAccounts++; //Increase account count
    }

    void deposit(float amt) {
        balance += amt;
        cout << "Deposited Successfully\n";
        cout << "New Balance = " << balance << endl;
    }

    void withdraw(float amt) {
        if (amt <= balance) { //Corrected condition
            balance -= amt;
            cout << "Withdrawn Successfully\n";
        } else {
            cout << "Insufficient Balance\n";
        }
        cout << "New Balance = " << balance << endl;
    }

    static int getTotalAccounts() { //Must be static
        return totalAccounts;
    }

    void input() {
        cout << "Enter the following information\n";
        cout << "Account Number = ";
        cin >> accountNumber;
        cout << "Balance = ";
        cin >> balance;
    }
};

//Define static member outside the class
int BankAccount::totalAccounts = 0;

int main() {
    BankAccount b1, b2;
    int ans;
    float money;

    b1.input();

    cout << "\nEnter the following case\n";
    cout << "1. Withdraw\t2. Deposit\n";
    cin >> ans;

    switch (ans) {
        case 1:
            cout << "Enter the amount you want to withdraw:\n";
            cin >> money;
            b1.withdraw(money);
            break;

        case 2:
            cout << "Enter the amount you want to deposit:\n";
            cin >> money;
            b1.deposit(money);
            break;

        default:
            cout << "INVALID CASE" << endl;
    }

    int t_Account = BankAccount::getTotalAccounts(); //Static function call
    cout << "\nTotal number of accounts created: " << t_Account << endl;

    return 0;
}
