/*WAP to implement dynamic memory allocation with new and delete
operators (for both simple variable and array variable).*/
#include<iostream>
using namespace std;
int main()
{
    int *arr,size;
    cout<<"Enter the number of memory to allocate dynamically"<<endl;
    cin>>size;
    arr = new int[size];//memory allocated dynamically
    for(int i = 0;i<size;i++)
    {
        cout<<"arr["<<i+1<<"] = ";
        cin>>arr[i];
    }
    //printing the content which was stored dynamically
    cout<<"Now displaying the inputs or contents"<<endl;
    for(int i = 0;i<size;i++)
    {
        cout<<"arr["<<i+1<<"] = "<<arr[i]<<endl;
    }
    delete[] arr;
    return 0;
}
