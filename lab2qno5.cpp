/*WAP to implement pointer with array.*/
#include<iostream>
using namespace std;

void pointer_array(int* parr, int n);

void pointer_array(int* parr, int n) {
    int temp;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; j++) {

            if(*(parr+i) > *(parr+j)) {
                temp = *(parr+i);
                *(parr+i) = *(parr+j);
                *(parr+j) = temp;
            }

        }
    }
    cout << "-------From UDF--------" <<endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Arr[" << i+1 << "] = " << *(parr+i) << endl;
    }
}
int main()
{
    int size;
    cout << "Enter how many array you want to give" << endl;
    cout << "ans = ";
    cin >> size;
    int* arrayPointer = new int[size];
    cout << " Enter the value of those array\n" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Arr[" << i+1 << "] = ";
        cin >> arrayPointer[i];
    }
    cout << "Arranging the order in ascending with pointers \n ";

    pointer_array(arrayPointer, size);
    
    cout << "---------From Main Function--------" <<endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Arr[" << i+1 << "] = " << arrayPointer[i] << endl;
    }
    delete[] arrayPointer;
    return 0;
}