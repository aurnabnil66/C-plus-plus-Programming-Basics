#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int i,upper,lower;
    cout << "Enter lower limit : ";
    cin >> lower;
    cout << "Enter upper limit : ";
    cin >> upper;

    srand(time(NULL));

    for ( i = lower; i < upper; i++)
    {
        int number = (rand() % (upper-lower + 1)) + lower;
        cout << number << "\n";
    }
    return 0;

    
    
}