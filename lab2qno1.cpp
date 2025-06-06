#include<iostream>
using namespace std;
inline float large(float x, float y)
{
    if(x>y)
    {
        return x;
    }
    else 
    {
        return y;
    }
}
int main()
{
    
    float ans = large(5,3);
    cout<<"The largest is = "<<ans;
    return 0;
}