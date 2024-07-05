#include<bits/stdc++.h>
using namespace std;
#define INF 999999
int M[5][5];
int s[5][5];
int P[10];

void input_dimension()
{
    int input;
    cout << "Enter the dimensions of the matrix : " << endl;
    for (int i = 0; i <= 5; i++)
    {
        cout << "P["<<i<<"]" << " = ";
        cin >> input;
        P[i] = input;
        cout << endl;
    }
    
}
void MCM()
{
    int n = (sizeof(P)/sizeof(P[0])) - 1;
    for (int i = 1; i <= n; i++)
    {
        M[i][i] = 0;
    }
    
    int q = 0, j = 0;
    for (int l = 0; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            /* code */
        }
        
    }
    
}