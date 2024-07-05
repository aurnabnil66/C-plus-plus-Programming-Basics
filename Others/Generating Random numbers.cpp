#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    int n, i;
    cout << "Enter quantity : ";
    cin >> n;
    time_t t;
    srand((unsigned)time(&t));

    for (i = 0; i < n; i++)
    {
        cout << (rand() % 100) + 1 << "\n";         // Numbers between 0 to a certain limit
    }
    
    return 0;
}