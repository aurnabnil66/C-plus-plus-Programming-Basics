#include<bits/stdc++.h>
using namespace std;
int n,w[20],x[20],m;
void print()
{
cout<<"printing"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<endl;
    }
}

void sumOfSub(int s,int k,int r)
{
    x[k]=1;
    if(s+w[k]==m)
        print();
    else if(s+w[k]+w[k+1]<=m)
        sumOfSub(s+w[k],k+1,r-w[k]);
    if(s+r-w[k]>=m&&s+w[k+1]<=m)
    {
        x[k]=0;
        sumOfSub(s,k+1,r-w[k]);
    }

}
int main()
{
    cout<<"enter n "<<endl;
    cin>>n;
    cout<<"enter m "<<endl;
    cin>>m;
    for(int i=1;i<=n;i++)
    {
        cout<<"enter w "<<i<<endl;
        cin>>w[i];
    }
    int s=0,r=0;
    for(int i=1;i<=n;i++)
    {
        r=r+w[i];
    }
    cout<<r<<endl;
    sumOfSub(s,1,r);

}
