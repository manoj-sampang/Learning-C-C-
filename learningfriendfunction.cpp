#include<iostream>
using namespace std;

class LearnFriendFunction {
    int* prr;
    int n;

public:
    // Constructor
    LearnFriendFunction(int getArr[], int getSize) {
        n = getSize;
        prr = new int[n];
        for (int i = 0; i < n; i++) {
            prr[i] = getArr[i];
        }
    }

    // Friend function declaration
    friend int Arr_Add(const LearnFriendFunction& l);

    // Destructor
    ~LearnFriendFunction() {
        delete[] prr;
        cout << "Memory Released!!! your memory is safe" << endl;
    }
};

// Friend function definition
int Arr_Add(const LearnFriendFunction& l) {
    int sum = 0;
    for (int i = 0; i < l.n; i++) {
        sum += l.prr[i];
    }
    return sum;
}

int main() {
    int* arr;
    int num;

    cout << "Enter the number of elements: ";
    cin >> num;

    arr = new int[num];

    cout << "Enter elements:\n";
    for (int i = 0; i < num; i++) {
        cout << "Arr[" << i + 1 << "] = ";
        cin >> arr[i];
    }

    // Create object and pass the array
    LearnFriendFunction s(arr, num);

    int sum = Arr_Add(s);
    cout << "The sum of the array elements is = " << sum << endl;

    delete[] arr; // Optional: this array was deep copied, so it's safe to delete here

    return 0;
}
