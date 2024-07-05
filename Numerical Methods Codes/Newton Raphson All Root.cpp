#include <bits/stdc++.h>
using namespace std;
int n = 3;
double a[4], b[4];
double f(double x)
{
    return ((x * x * x * a[3]) + (a[2] * x * x) + a[1] * x + a[0]);
}
double fp(double x)
{
    return ((3 * a[3] * x * x) + 2 * a[2] * x + a[1]);
}
int main()
{
    double x0 = 2.5, e, x1 = 0;
    a[3] = 1;
    a[2] = -7;
    a[1] = 15;
    a[0] = -9;
    while (n > 1)
    {
        do
        {
            x1 = x0 - (f(x0) / fp(x0));
            e = fabs(x1 - x0);
            x0 = x1;
            cout << x1 << endl;
        } while (e > 0.00001);
        cout << "The root is: " << x1 << endl;
        b[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            b[i] = a[i + 1] + b[i + 1] * x1;
        }
        for (int i = n; i >= 0; i--)
        {
            a[i] = b[i];
        }
        n--;
    }
    printf("The root is: %lf", -a[0] / a[1]);
    return 0;
}
