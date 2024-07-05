#include<iostream>
using namespace std;
struct Person
{
    char name[50];
    int age;
    double salary;
};

Person getData(Person);
void display_Data(Person);

int main()
{
    Person p,x;
    x = getData(p);
    p = x;

    display_Data(p);

    return 0;
}

Person getData(Person p)
{
    cout << "Enter name : ";
    cin >> p.name;
    
    cout << "Enter age : ";
    cin >> p.age;

    cout << "Enter Salary : ";
    cin >> p.salary;

    return p;
}

void display_Data(Person p)
{
    cout << "\nDisplaying Information : " << endl;
    cout << "Name : " << p.name << endl;
    cout << "Age : " << p.age << endl;
    cout << "Salary : " << p.salary << endl;

}