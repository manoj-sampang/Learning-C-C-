#include<iostream>
using namespace std;
int main( )
{
int n, *p, sum=0;
cout<<"Enter the size of the array:"<<endl;
cin >> n;
p=new int[n];
cout<<"No. the elements in Dynamically allocated memory of array of size: " << n <<endl;
for(int i=0; i<n; i++){
cin>>*(p+i); //cin>>*(p+i);
}
cout<<"The entered elements in the array are:"<<endl;
for(int i=0;i<n;i++)cout<<p[i]<<"\t"; //cout<<*(p+i)<<"\t";
for(int i=0; i<n; i++)sum=sum+p[i]; //sum=sum+*(p+i);
float avg=float(sum)/n;
cout<<"\nThe average is:"<<avg;
delete[] p;
return 0;
}
