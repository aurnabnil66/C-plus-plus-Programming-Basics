#include<bits/stdc++.h>
#include<math.h>
using namespace std;
double func(double x)
{
    double a = 3 * x - cos(x * (3.182 / 180)) - 1;
    return a;
}
int main()
{
    cout.precision(6);
    cout.setf(ios::fixed);
    double a,b,c,e,fx0,fx1,fx2;
    int iter = 1;

    cout << "Enter initial guesses : " << endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cout << "Enter error value : ";
    cin >> e;

    cout << "Iteration" << setw(12) << "a" << setw(12) << "b" << setw(12) << "c" << setw(12) << "f(c)" << setw(12) << "|c - b|" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;

    do
    {
        fx0 = func(a);
        fx1 = func(b);
        c = (fx1 * a - fx0 * b) / (fx1 - fx0);
        fx2 = func(c);
        a = b;
        b = c;

        cout << iter << setw(16) << a << setw(12) << b << setw(12) << c << setw(12) << func(c) << setw(12) << fabs(c - b) << endl;

        iter++;

    }
    while(fabs(c - b) > e);
    cout << "Root is : " << c << endl;
    return 0;
}
