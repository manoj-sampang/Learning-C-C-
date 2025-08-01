/*Develop a simple Banking System with two classes: Account and
Transaction. The Account class represents bank accounts, including private
data members for accountNumber, accountHolder, and balance, along with
public member functions for initialization and data retrieval. The Transaction
class handles individual transactions, containing private data members
accountNumber, transactionType, and amount, and a constructor for
transaction setup. Your task is to create a Friend function named
processTransaction that links the Account and Transaction classes. This
function should update the account balance based on the transaction type
(deposit or withdrawal) and return the updated account balance. Implement
the classes and function in C++ and demonstrate the banking system's
functionality with appropriate test cases.*/

#include <iostream>
using namespace std;

class Transaction; // Forward declaration

class Account {
    string accountNumber, accountHolder;
    double balance;

public:
    void input() {
        cin.ignore(); // Clear input buffer before getline
        cout << "Enter the asked details for creating account" << endl;
        cout << "Account Number: ";
        getline(cin, accountNumber);
        cout << "Account Holder: ";
        getline(cin, accountHolder);
        cout << "Balance to Deposit (Initially): ";
        cin >> balance;
    }

    void display() const {
        cout << "\n=== Displaying Account Details ===\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Balance: " << balance << "\n";
    }

    friend void processTransaction(Account &a, const Transaction &t);  // friend function
};

class Transaction {
    string transactionType;
    double amount;

public:
    void inputTransaction() {
        cout << "\nEnter transaction type (deposit or withdraw): ";
        cin >> transactionType;
        cout << "Enter amount: ";
        cin >> amount;
    }

    string getType() const { return transactionType; }
    double getAmount() const { return amount; }

    friend void processTransaction(Account &a, const Transaction &t);
};

void processTransaction(Account &a, const Transaction &t) {
    if (t.transactionType == "deposit") {
        a.balance += t.amount;
        cout << "Deposit successful!\n";
    } else if (t.transactionType == "withdraw") {
        if (t.amount > a.balance) {
            cout << "Insufficient funds!\n";
        } else {
            a.balance -= t.amount;
            cout << "Withdrawal successful!\n";
        }
    } else {
        cout << "Invalid transaction type!\n";
    }
}

int main() {
    Account A;
    int choice;

    while (true) {
        cout << "\n=== Menu ===\n";
        cout << "1. Create Account\n";
        cout << "2. Transaction\n";
        cout << "3. Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                A.input();
                break;
            case 2: {
                Transaction T;
                T.inputTransaction();
                processTransaction(A, T);
                A.display();
                break;
            }
            case 3:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
