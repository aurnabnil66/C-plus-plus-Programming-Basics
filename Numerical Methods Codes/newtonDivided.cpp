#include<bits/stdc++.h>
using namespace std;
double n;
double x[20],y[20],dfx[10],d2fx[10],d3fx[10];
double yp=0,xp;
void newtonDivide()
{
    for(int i=0;i<n-1;i++)
    {
       dfx[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
    }
     for(int i=0;i<n-2;i++)
    {
       d2fx[i]=(dfx[i+1]-dfx[i])/(x[i+2]-x[i]);
    }
     for(int i=0;i<n-3;i++)
    {
       d3fx[i]=(d2fx[i+1]-d2fx[i])/(x[i+3]-x[i]);
    }

    yp=y[0]+(xp-x[0])*dfx[0]+(xp-x[0])*(xp-x[1])*d2fx[0]+(xp-x[0])*(xp-x[1])*(xp-x[2])*d3fx[0];
    cout<<"yp is "<<yp<<endl;
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
    newtonDivide();


}
