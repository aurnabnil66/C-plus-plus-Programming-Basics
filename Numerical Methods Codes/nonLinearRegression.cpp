#include<bits/stdc++.h>
using namespace std;
float n,degree;
float x[20],y[20],sumx=0,sumy=0,sumx2=0,sumxy=0;
void nonLinear()
{
    for(int i=0;i<n;i++)
    {
        sumx= sumx + log(x[i]);
      sumx2 = sumx2 + log(x[i] )*log( x[i]);
     sumy= sumy + log(y[i]);
       sumxy = sumxy + log(x[i] )* log(y[i]);
    }
  float  b = (n * sumxy - sumx * sumy)/(n*sumx2 - sumx * sumx);
  float  a = (sumy - b*sumx)/n;
  cout<<b<<endl;
  cout<<a<<endl;
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
    nonLinear();


}
