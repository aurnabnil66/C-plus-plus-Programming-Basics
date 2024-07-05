#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>length;
vector<vector<int>>arrow;// -1=diagonal arrow -2=side arrow -3=up arrow
int n,m;
string x,y;
void printLCS(int i,int j)

{
    if(i==0||j==0)
        return;
        else if(arrow[i][j]==-1)
    {
        printLCS(i-1,j-1);
        cout<<x[i-1];
    }
     else if(arrow[i][j]==-3)
    {
        printLCS(i-1,j);

    }
    else
        printLCS(i,j-1);
}
void LCS()
{

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                length[i][j]=length[i-1][j-1]+1;
                arrow[i][j]=-1;

            }
            else if(length[i-1][j]>=length[i][j-1]&&x[i-1]!=y[j-1])
            {
                length[i][j]=length[i-1][j];
                arrow[i][j]=-3;

            }
             else if(length[i-1][j]<=length[i][j-1]&&x[i-1]!=y[j-1])
            {
                length[i][j]=length[i][j-1];
                arrow[i][j]=-2;

            }
        }
    }
         for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<length[i][j]<<" ";
        }
         cout<<endl;
    }
        cout<<"arrow"<<endl;
     for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<arrow[i][j]<<" ";
        }
         cout<<endl;
    }



}
int main()
{
   cout<<"enter size of x string"<<endl;
   cin>>m;
       cout<<"enter size of y string"<<endl;
    cin>>n;
     cout<<" enter x string"<<endl;
     cin>>x;
      cout<<" enter y string"<<endl;
     cin>>y;
    for(int i=0;i<=m;i++)
    {
        vector<int>row;
        for(int j=0;j<=n;j++)
        {
            row.push_back(0);
        }
        length.push_back(row);
    }
    for(int i=0;i<=m;i++)
    {
        vector<int>row;
        for(int j=0;j<=n;j++)
        {
            row.push_back(0);
        }
        arrow.push_back(row);
    }



      LCS();
       int i=m,j=n;
       printLCS(i,j);


}
