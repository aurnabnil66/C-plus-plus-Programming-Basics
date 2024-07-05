#include<iostream>
using namespace std;
struct Student
{
    char name[30];
    int age;
};
struct Student getInformation();
int main()
{
    struct Student s;
    s = getInformation();
    cout << "\nDisplaying Information\n";
    cout << "Name : " << s.name << endl;
    cout << "Age : " << s.age << endl;
}
struct Student getInformation()
{
    struct Student x;
    cout << "Enter name : ";
    cin >> x.name;
    cout << "Enter age : ";
    cin >> x.age;

    return x;
}
