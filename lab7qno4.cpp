/*You have a BankAccount base class, and your objective is to implement
constructors and a destructor in it. Additionally, you'll derive a specialized
SavingsAccount class from the base class.
BankAccount Class:

Ø Create a base class named BankAccount with attributes
accountNumber (string): Account number and balance (double):
Account balance.
Ø Implement a parameterized constructor to initialize attributes and
implement a destructor displaying "Bank account with account
number [accountNumber] is being closed."
SavingsAccount Class:
Ø Derive SavingsAccount from BankAccount and add an attribute
interestRate (double): Annual interest rate.
Ø Implement a parameterized constructor to initialize attributes.
Write a C++ program that:
a. Creates instances of SavingsAccount and sets attributes.
b. Demonstrates the behavior of constructors and the destructor during
object creation and destruction.*/

#include<iostream>
using namespace std;

class BankAccount {
    string accountNumber;
    double balance;
public:
    BankAccount(string acc, double bal) {
        accountNumber = acc;
        balance = bal;
        cout << "Bank account [" << accountNumber << "] is created with balance $" << balance << endl;
    }

    ~BankAccount() {
        cout << "Bank account with account number [" << accountNumber << "] is being closed." << endl;
    }
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(string acc, double bal, double rate) : BankAccount(acc, bal), interestRate(rate) {
        cout << "SavingsAccount with interest rate " << interestRate << "% created." << endl;
    }

    ~SavingsAccount() {
        cout << "SavingsAccount destructor called." << endl;
    }
};

int main() {
    {
        SavingsAccount S1("102343h", 64353.75, 7.9);
        cout << "Main: Doing something with the savings account..." << endl;
    }

    cout << "Main: End of program." << endl;

    return 0;
}
