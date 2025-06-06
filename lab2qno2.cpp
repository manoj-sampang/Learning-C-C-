/*Write a C++ function called calculateDiscountedPrice that calculates the
discounted price of an item. The function should have two parameters: price
(representing the original price) and discountPercentage (with a default value
of 10%). The function should return the calculated discounted price.
In the main function, prompt the user to enter the original price of an item.
Then, call the calculateDiscountedPrice function twice: once with the default
discount percentage and once with a specific discount percentage entered by
the user. Finally, print the original price and the two discounted prices.*/
#include<iostream>
using namespace std;
float calc_dis_price(float price, float d=10)
{
    float d_price;
    d_price=price-((d/100)*price);
    return d_price;
}
int main()
{
    float op;
    float ans;
    int dp;
    cout<<"Enter the price you want the discount of\n";
    cin>>op;
    cout<<"Enter the discount percentage too\n";
    cin>>dp;
    cout<<"-----Without Default parameter-----\n";
    ans=calc_dis_price(op,dp);
    cout<<"Without = "<<ans<<endl;
    cout<<"-----With Default parameter-----\n";
    ans=calc_dis_price(op);
    cout<<"with  = "<<ans<<endl; 
    return 0;
}