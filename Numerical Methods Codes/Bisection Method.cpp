#include<bits/stdc++.h>
#include<math.h>
using namespace std;

float func(float x);

float func(float x)
{
    float a = x*x - 4*x - 10;
    return a;
}

int main()
{
    float a,b,c,e,fa,fb,fc;
a:
    cout << "Enter the values : " << endl;
    cout << "Enter a : ";
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    cout << "Enter the degree of accuracy : ";
    cin >> e;

    int iter = 0;
    if((func(a) * func(b)) > 0)
    {
        cout << "Enter different values : ";
        goto a;
    }
    else
    {
        cout << endl;
        cout << "Iteration" << setw(14) << "a" << setw(18) << "b" << setw(18) << "c" << setw(18) << "f(c)" << setw(18) << "|a - b|" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        while(fabs(a - b) > e)
        {
            c = (a + b)/2.0;
            fa = func(a);
            fb = func(b);
            fc = func(c);
            iter++;
            cout << iter << setw(18) << a << setw(18) << b << setw(18) << c << setw(18) << fc << setw(18) << fabs(a - b) << endl;

            if(fc == 0)
            {
                cout << "The root of the equation : " << c << endl;
            }
            else if((fa * fc) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }
    }
    cout << "The root of the equation : " << c << endl;

}
