/*Write a C++ function called updateEmployeeSalary that takes a reference
parameter salary and increases it by a given percentage. In the main function,
prompt the user to enter an employee's current salary and the percentage
increase. Call the updateEmployeeSalary function, passing the entered salary
and percentage increase. The function should modify the salary by increasing
it based on the given percentage. Finally, print the original salary and the
updated salary to verify the changes.*/
#include<iostream>
using namespace std;
void updateEmployeeSalary(float& ref_salary, float& ref_percent);
void display(float& ref_salary, float& ref_percent);

void updateEmployeeSalary(float& ref_salary, float& ref_percent) {
    cout << "Original Salary = " << ref_salary << endl;
    ref_salary += (ref_percent/100*ref_salary);
}

void display(float& ref_salary, float& ref_percent) {
    cout << "Updated Salary = " << ref_salary << endl;
}

int main()
{
    float salary;
    float percent;
    cout << "Enter the employee's current salary." << endl;
    cout << "Current Salary = ";
    cin >> salary;
    cout << "Enter the percentage increase\n";
    cout << "Percentage Increase = ";
    cin >> percent;
    updateEmployeeSalary(salary, percent);//implement of call by refernce
    display(salary, percent);//call by refernce see the behavour
    return 0;
}