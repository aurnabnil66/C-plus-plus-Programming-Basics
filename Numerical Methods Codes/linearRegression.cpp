#include<bits/stdc++.h>
using namespace std;
double n;
double x[20],y[20];

void linear()
{
    double sumx=0,sumx2=0,sumy=0,sumxy=0;
    for(int i=0;i<n;i++)
    {
        sumx=sumx+x[i];
        sumx2=sumx2+(x[i]*x[i]);
        sumy=sumy+y[i];
        sumxy=sumxy+(x[i]*y[i]);
    }
    double b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    double a=(sumy-b*sumx)/n;
    cout<<"b "<<b<<endl;
     cout<<"a "<<a<<endl;
}
int main()
{
    cout<<"enter n "<<endl;
    cin>>n;
   // cout<<"enter xp "<<endl;
  //  cin>>xp;
    for(int i=0;i<n;i++)
    {
        cout<<"enter x"<<i<<endl;
        cin>>x[i];
        cout<<"enter y"<<i<<endl;
        cin>>y[i];
    }
    linear();


}

