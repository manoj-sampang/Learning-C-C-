/*Write a program to implement linear search algorithm */

#include <iostream>
using namespace std;

class LinearSearchAlgorithm {
    float *arr;
    int search;

public:
    LinearSearchAlgorithm() {
        arr = nullptr;
    }

    LinearSearchAlgorithm(int size) {
        arr = new float[size];
    }

    void input(int size) {
        for (int i = 0; i < size; ++i) {
            cout << "Arr[" << i + 1 << "] = ";
            cin >> arr[i];
        }
        cout << "Enter number you want to search: ";
        cin >> search;
    }

    int return_index(int size, int index = 0) {
        if (index == size) {
            return -1;  // Not found
        }
        if (arr[index] == search) {
            return index;
        }
        return return_index(size, index + 1);  // Recurse
    }

    float display(int index) {
        return arr[index];
    }

    ~LinearSearchAlgorithm() {
        delete[] arr;
        cout << "Memory Disallocated\n";
    }
};

int main() {
    int size;
    cout << "--- Linear Search Algorithm ---\n";
    cout << "Enter how many elements you want to allocate: ";
    cin >> size;

    LinearSearchAlgorithm l(size);
    l.input(size);

    int result = l.return_index(size, 0);
    if (result != -1) {
        cout << "Element found at index " << result << " with value = " << l.display(result) << endl;
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}
