#include<iostream>
using namespace std;
int main()
{
    int val;
    cout << "Enter a variable = ";
    cin >> val;
    cout << "value of the variable = " << val <<endl;
    cout << "Address of the variable = " << &val << endl;

    int *ptr;
    ptr = &val;

    cout << "value of the pointer = " << *ptr << endl;
    cout << "Address of the pointer = "<< ptr << endl;


}