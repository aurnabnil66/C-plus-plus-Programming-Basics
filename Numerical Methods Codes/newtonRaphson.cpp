#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;
float fun(float x)
{
    return x*x*x-x-1;
}
float funPrime(float x)
{
    return 3*x*x-1;
}
int main()
{
    float xn,xn1,e,fx,fpx;
    cout<<"enter initial"<<endl;
    cin>>xn;
     cout<<"enter error"<<endl;
    cin>>e;
    fx=fun(xn);
    cout<<"fx "<<fx<<endl;
    fpx=funPrime(xn);
    cout<<"fpx "<<fpx<<endl;
    xn1=xn-(fx/fpx);
    cout<<"xn1 "<<xn1<<endl;

    while(fabs((xn1-xn)/xn1)>e)
    {

        xn=xn1;
        fx=fun(xn);
       fpx=funPrime(xn);
       xn1=xn-(fx/fpx);

    }
    cout<<"root "<<xn1<<endl;
}

