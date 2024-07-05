#include<iostream>
using namespace std;
typedef struct distance         // Derived type struct distance
{
    int feet;
    double inch;
}distances;                     // Using typedef in order to simplify
int main()
{
    distances dist1,dist2,sum;     // As we are using typedef, we don't need to write struct
    
    cout << "1st Distance" <<endl;
    cout << "Enter distance in feet : ";
    cin >> dist1.feet;
    cout << "Enter distance in inch : ";
    cin >> dist1.inch;
    
    cout << "2nd Distance" <<endl;
    cout << "Enter distance in feet : ";
    cin >> dist2.feet;
    cout << "Enter distance in inch : ";
    cin >> dist2.inch;

    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    while (sum.inch >= 12)
    {
        sum.feet++;
        sum.inch = sum.inch - 12;
    }

    cout << "Feet : " << sum.feet << endl;
    cout << "Inch : " << sum.inch << endl;
    return 0;
    
}