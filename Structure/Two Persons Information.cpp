#include <iostream>
using namespace std;
struct Persons
{
    int month;
    double salary;
};
int main()
{
    struct Persons p1,p2;
    cout << "1st person" <<endl;
    cout << "Enter month : ";
    cin >> p1.month;
    cout << "Enter salary : ";
    cin >> p1.salary; 

    cout << "2nd person" <<endl;
    cout << "Enter month : ";
    cin >> p2.month;
    cout << "Enter salary : ";
    cin >> p2.salary;
    
    cout << "\n";
    cout << "First Person" << endl;
    cout << "Month = " << p1.month << endl;
    cout << "Salary =  " << p1.salary << endl;

    cout << "\n";
    cout << "Second Person" << endl;
    cout << "Month = " << p2.month << endl;
    cout << "Salary =  " << p2.salary << endl;
   
}
