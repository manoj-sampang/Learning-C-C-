#include<iostream>
using namespace std;

class Truth_Table {
public:
    int calculate_output(int a, int b, int choice);
    void negation();
    void conjunction();
    void disjunction();
    void implication();
    void bi_implication();
};

// This function returns the result instead of printing
int Truth_Table::calculate_output(int a, int b, int choice) {
    switch (choice) {
        case 1: // Negation
            return !a;
        case 2: // Conjunction
            return a && b;
        case 3: // Disjunction
            return a || b;
        case 4: // Implication (True → False = False)
            return (!a) || b;
        case 5: // Bi-implication
            if(a==b)
            {
                return 0;
            }
            else {
                return 1;
            }
        default:
            return -1; // Invalid
    }
}

void Truth_Table::negation() {
    cout << "\n---- NEGATION ----\n";
    cout << "A\tOutput\n";
    for (int i = 0; i <= 1; ++i) {
        cout << i << "\t" << calculate_output(i, 0, 1) << endl;
    }
}

void Truth_Table::conjunction() {
    cout << "\n---- CONJUNCTION ----\n";
    cout << "A\tB\tOutput\n";
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            cout << i << "\t" << j << "\t" << calculate_output(i, j, 2) << endl;
        }
    }
}

void Truth_Table::disjunction() {
    cout << "\n---- DISJUNCTION ----\n";
    cout << "A\tB\tOutput\n";
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            cout << i << "\t" << j << "\t" << calculate_output(i, j, 3) << endl;
        }
    }
}

void Truth_Table::implication() {
    cout << "\n---- IMPLICATION ----\n";
    cout << "A\tB\tOutput\n";
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            cout << i << "\t" << j << "\t" << calculate_output(i, j, 4) << endl;
        }
    }
}

void Truth_Table::bi_implication() {
    cout << "\n---- BI-IMPLICATION ----\n";
    cout << "A\tB\tOutput\n";
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            cout << i << "\t" << j << "\t" << calculate_output(i, j, 5) << endl;
        }
    }
}

int main() {
    Truth_Table t;
    int choose;
    while (true) {
        cout << "\nThis is a menu-driven Program for Truth Tables of logic operations\n";
        cout << "1. Negation\n"
             << "2. Conjunction\n"
             << "3. Disjunction\n"
             << "4. Implication\n"
             << "5. Bi-implication\n"
             << "6. Exit\n";
        cout << "Choose (1-6): ";
        cin >> choose;

        switch (choose) {
            case 1:
                t.negation();
                break;
            case 2:
                t.conjunction();
                break;
            case 3:
                t.disjunction();
                break;
            case 4:
                t.implication();
                break;
            case 5:
                t.bi_implication();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid input!!!" << endl;
        }
    }
}
