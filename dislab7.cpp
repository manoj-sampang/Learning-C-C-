#include <iostream>
using namespace std;

class Boolean {
    int **i, **j, **res;
    int size;

public:
    Boolean(int index1) {
        size = index1;

        // Allocate memory
        i = new int*[size];
        j = new int*[size];
        res = new int*[size];

        for (int k = 0; k < size; ++k) {
            i[k] = new int[size];
            j[k] = new int[size];
            res[k] = new int[size];
        }
    }

void input() {
    cout << "Enter matrix A (only 0 or 1):\n";
    for (int k = 0; k < size; ++k) {
        for (int l = 0; l < size; ++l) {
            do {
                cout << "A[" << k << "][" << l << "] = ";
                cin >> i[k][l];
                if (i[k][l] != 0 && i[k][l] != 1) {
                    cout << "Invalid input! Please enter 0 or 1.\n";
                }
            } while (i[k][l] != 0 && i[k][l] != 1);
        }
    }

    cout << "Enter matrix B (only 0 or 1):\n";
    for (int k = 0; k < size; ++k) {
        for (int l = 0; l < size; ++l) {
            do {
                cout << "B[" << k << "][" << l << "] = ";
                cin >> j[k][l];
                if (j[k][l] != 0 && j[k][l] != 1) {
                    cout << "Invalid input! Please enter 0 or 1.\n";
                }
            } while (j[k][l] != 0 && j[k][l] != 1);
        }
    }
}


    void calculate_join() {
        for (int k = 0; k < size; ++k) {
            for (int l = 0; l < size; ++l) {
                res[k][l] = i[k][l] | j[k][l]; // Boolean join using OR
            }
        }
    }

    void calculate_meet() {
        for (int k = 0; k < size; ++k) {
            for (int l = 0; l < size; ++l) {
                res[k][l] = i[k][l] & j[k][l]; // Boolean meet using AND
            }
        }
    }

    void display() {
        cout << "Result Matrix:\n";
        for (int k = 0; k < size; ++k) {
            cout << "| ";
            for (int l = 0; l < size; ++l) {
                cout << res[k][l] << " ";
            }
            cout << "|\n";
        }
    }

    ~Boolean() {
        for (int k = 0; k < size; ++k) {
            delete[] i[k];
            delete[] j[k];
            delete[] res[k];
        }
        delete[] i;
        delete[] j;
        delete[] res;
    }
};
int main() {
    int index, choice;
    cout << "Boolean Matrix Operation\n";
    cout << "Enter matrix size (NxN): ";
    cin >> index;

    Boolean b(index);
    cout << "----------Only enter either 1 or 0 as they are boolean-----------" << endl;
    b.input();

    cout << "Choose Operation:\n1. Join (A OR B)\n2. Meet (A AND B)\nChoice: ";
    cin >> choice;

    if (choice == 1)
        b.calculate_join();
    else
        b.calculate_meet();

    b.display();
    return 0;
}
