#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void func(int x, int n)
{
    x = n * 2;
}
int main()
{
    int i, j, x, n;
    clock_t start_time, end_time;
    double time_passed;

    //Unsigned Integer
    cout << CLOCKS_PER_SEC << endl;

    start_time = clock();
    cout << "Start Time : " << start_time << endl;

    n = 12345678;
    for (i = 0; i < 100000000; i++)
    {
        for (j = 0; j < 10; j++)
        {
            x = n * 2;
        }
    }

    end_time = clock();
    cout << "End Time : " << end_time << endl;

    time_passed = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Total Time : " << time_passed << endl;
}