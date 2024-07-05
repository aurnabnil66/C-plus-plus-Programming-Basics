#include<bits/stdc++.h>
#include<math.h>
using namespace std;
double f(double x)
{
    double a = 3 * x - cos(x * (3.182/ 180)) - 1;
    return a;
}
double g(double x)
{
    double a = (cos(x * (3.182/ 180)) + 1) / 3;
    return a;
}
int main()
{
    double a,c,e;
    cout << "Enter initial guess : ";
    cin >> a;
    cout << "Enter error : ";
    cin >> e;

    c = g(a);

    while(abs(c - a) > 0)
    {
        a = c;
        c = g(a);
    }
    cout << "Root : " << c << endl;
}
