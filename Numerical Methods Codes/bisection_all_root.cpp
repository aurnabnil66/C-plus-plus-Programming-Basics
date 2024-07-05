#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return ((x*x)-(4*x)-10);
}
int main()
{
    double a=-4.00,b=6.00,e=0.0001,c,x1,x2,x3,x4,dx=.5;
    x1=a;
    do
    {
        x2=x1+dx;
        if(f(x1)*f(x2)<0)
        {
            x3=x1;
            x4=x2;
            do
            {
                c=(x3+x4)/2;
                if(f(c)==0)
                {
                    break;
                }
                if(f(x3)*f(c)<=0)
                {
                    x4=c;
                }
                else
                {
                    x3=c;
                }
            }
            while(fabs(x3-x4)>e);
            cout<<"The root is: "<<c<<endl;
        }
        x1=x2;
    }while(x2<=b);
    return 0;
}
/*
*/
