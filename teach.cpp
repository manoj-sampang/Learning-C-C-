#include <iostream>
using namespace std;

class BankAccount {
    string accountNumber, name;
    double balance;
    static int track;

public:
    BankAccount() : accountNumber("0"), name("Unknown"), balance(0.00) {}
    BankAccount(string a, string n, double b) : accountNumber(a), name(n), balance(b) {
        track++;
    }

    static void show_account() {
        cout << "No. of Accounts Created: " << track << endl;
    }

    void display() {
        cout << "\n--- ACCOUNT INFORMATION ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Total Balance: " << balance << endl;
    }

    void transaction() {
        int choose;
        cout << "\nChoose Either" << endl;
        cout << "1. Withdraw" << "\t 2. Deposit" << endl;
        cin >> choose;
        if (choose == 1) {
            withdraw();
        } else {
            deposit();
        }
    }

    void withdraw() {
        double amt;
        cout << "Amount for Withdrawl = ";
        cin >> amt;
        if (amt <= balance) {
            balance -= amt;
            cout << "Withdrawal Successful!" << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void deposit() {
        double amt;
        cout << "Amount for Deposit = ";
        cin >> amt;
        balance += amt;
        cout << "Deposit Successful!" << endl;
    }
};

// initialize static variable
int BankAccount::track = 0;

int main() {
    int choose;
    BankAccount B; // global object to hold the current account

    do {
        cout << "\n=== Choose instruction to perform ===" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. TRANSACTION (Withdraw / Deposit)" << endl;
        cout << "3. Show Account Information" << endl;
        cout << "4. Total Accounts Created " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choose;

        switch (choose) {
            case 1: {
                string name, account;
                double bal;
                cout << "Enter User Name: ";
                cin.ignore(); // clear newline from previous input
                getline(cin, name);
                cout << "Account Number: ";
                getline(cin, account);
                cout << "Initial Deposit: ";
                cin >> bal;
                B = BankAccount(account, name, bal); // constructor runs
                cout << "Account Created Successfully!\n";
                break;
            }
            case 2:
                B.transaction();
                break;
            case 3:
                B.display();
                break;
            case 4:
                BankAccount::show_account();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
        }
    } while (choose != 5);

    return 0;
}
