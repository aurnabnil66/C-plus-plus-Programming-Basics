#include<bits/stdc++.h>
using namespace std;
double n;
double x[20],y[20];
double yp=0,xp;
void lagrange()
{
     for(int i=0;i<n;i++)
    {
        double pxp=1;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                pxp=pxp*(xp-x[j])/(x[i]-x[j]);
            }
        }
        yp=yp+pxp*y[i];
    }
    cout<<"ans is "<<yp<<endl;
}
int main()
{
    cout<<"enter n "<<endl;
    cin>>n;
    cout<<"enter xp "<<endl;
    cin>>xp;
    for(int i=0;i<n;i++)
    {
        cout<<"enter x"<<i<<endl;
        cin>>x[i];
        cout<<"enter y"<<i<<endl;
        cin>>y[i];
    }
    lagrange();


}
