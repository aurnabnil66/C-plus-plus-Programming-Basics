#include<iostream>
using namespace std;
struct Distance
{
    double feet;
    double inch;
};
int main()
{
    Distance *ptr,d;
    ptr = &d;
    
    cout << "Enter feet : ";
    cin >> ptr->feet;                 // ptr->feet is same as (*ptr).feet 
    // This is because the . operator has a higher precedence than the * operator.

    double result = 12*((*ptr).feet);

    cout << (*ptr).feet << " feet = " << result << endl;
}
