#include<bits/stdc++.h>
#include<math.h>
using namespace std;
double f(double x)
{
    double a = 3 * x - cos(x * (3.182 / 180)) - 1;
    return a;
}
double fprime(double x)
{
    double b = 3 - sin(x * (3.182 / 180));
    return b;
}
int main()
{
    double x,x1,fx,fx1,e;
    cout.precision(4);
    cout.setf(ios::fixed);
    cout << "Enter initial guess : ";
    cin >> x1;
    cout << "Enter desired accuracy : ";
    cin >> e;

    int iter = 1;
    cout <<"Iteration"<< setw(12) << "x[i]" << setw(20) << "x[i + 1]" << setw(20) << "| x[i +1] - x[i] |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    do
    {
        x = x1;
        fx = f(x);
        fx1 = fprime(x);
        x1 = x - (fx/fx1);
        cout <<iter<< setw(12) << x << setw(16) << x1 << setw(16) << fabs(x1 - x) << endl;
        iter++;
    }while(fabs(x1 - x) >= e);

    cout << "The root is " << x1 << endl;
    return 0;
}
