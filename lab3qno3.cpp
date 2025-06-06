/*Create a C++ class called 'Person' with a constructor that initializes the name
and age member variables. Implement a copy constructor that creates a new
Person object by copying the name and age from an existing object. Show the
usage of both constructors by creating an object named 'person1' with name
'Sunil' and age 25. Then, use the constructors to create another object named
'person2' with the same name and age as 'person1'. Print the details (name and
age) of 'person2'.*/
#include<iostream>
using namespace std;
class Person{
    string name;
    int age;
    public: 
        Person(string u_name, int u_age)
        {
            name = u_name;
            age = u_age;
        }
        Person(const Person &c)
        {
            name = c.name;
            age = c.age;
            cout<<"Copy constructor called"<<endl;
        }
        void display();
};
void Person::display()
        {
            cout<<"Name = "<<name;
            cout<<"\tAge = "<<age;
        }
int main()
{
    Person person1("Sunil",25);
    Person person2 = person1;
    cout<<"\n-----Display first data-----"<<endl;
    person1.display();
    cout<<"\n------Display copied data-----"<<endl;
    person2.display();
    return 0;
}