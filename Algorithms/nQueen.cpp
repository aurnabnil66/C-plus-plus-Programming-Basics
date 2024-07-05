#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a;
int x[10];
bool place(int k,int i)
{
    for(int j=1;j<=k-1;j++)
    {
        if(x[j]==i||fabs(x[j]-i)==fabs(j-k))
            return false;
    }
    return true;
}
void print(int i,int n)
{
    cout<<"soln no "<<i<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<endl;
    }
}

void nQueens(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
                print(i,n);
            else
                nQueens(k+1,n);
        }
    }
}

int main()
{
     int  n;
     cout<<"enter n"<<endl;
     cin>>n;
     int k=1;
     nQueens(k,n);
}
