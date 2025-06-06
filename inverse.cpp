#include<iostream>
using namespace std;
class inverse{
    float **mptr;
    int order;
    public:
    inverse(float **p,int num)
    {
        mptr = p;
        order = num;
    }
    void input()
    {
        cout<<"Enter the matrix of order"<<order<<"*"<<order<<endl;
        for(int i=0;i<order;i++)
        {
            for(int j = 0 ;j<order;j++)
            {
                cout<<"A["<<i<<"]["<<j<<"] = ";
                cin>>mptr[i][j];
            }
        }
    }
    void calc_inverse()
    {
        
    }
    ~inverse() 
    {
    for(int i = 0; i < order; i++)
        delete[] mptr[i];
    delete[] mptr;
    }
};
int main()
{
    int order;
    cout<<"Enter the order of matrix(n*n)"<<endl;
    cout<<"Order = ";
    cin>>order;
    float** mptr = nullptr;//pointer to pointer
    mptr = new float* [order];//here each row of the previous pointer is now a pointer as well
    for(int i=0; i<order;i++)
    {
        mptr[i] = new float[order];//this creates a array of columns for each row which is a pointer
    }
    
    for(int i = 0 ;i<order;i++)
    {
        delete[] mptr[i];
    }
    delete[] mptr;
    return 0;
}