#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> d;
vector<vector<int>> pi;
int node, weight;
void floydWarshall()
{

    vector<vector<int>> dnew;
    for (int k = 0; k < node; k++)
    {
        // creating new vector for distance
        for (int r = 0; r < node; r++)
        {
            vector<int> temp;
            for (int s = 0; s < node; s++)
            {
                temp.push_back(d[r][s]);
            }
            dnew.push_back(temp);
        }
        cout << "after creating newd for k " << k << endl;
        // i j starts from here
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j] && i != j && i != k && j != k)
                {
                    dnew[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        } // i j ends here

        // printing newd
        cout << "dnew for k " << k << endl;
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                cout << dnew[i][j] << " ";
            }
            cout << endl;
        }
        // printing pi
        cout << "pi for k " << k << endl;
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                cout << pi[i][j] << " ";
            }
            cout << endl;
        }
        // copying dnew to d
        for (int i = 0; i < node; i++)
        {
            for (int j = 0; j < node; j++)
            {
                d[i][j] = dnew[i][j];
            }
        }
    }
}
void printingPath(int source, int dest)
{
    if (source == dest)
        cout << dest << "->";
    else if (pi[source][dest] == -1)
        cout << "no path exists" << endl;
    else
        printingPath(source, pi[source][dest]);
    cout << dest << "->";
}
int main()
{
    cout << "enter node" << endl;
    cin >> node;
    for (int i = 0; i < node; i++)
    {
        vector<int> row;
        for (int j = 0; j < node; j++)
        {
            // cout<<"enter a"<<i<<j<<endl;
            cin >> weight;
            row.push_back(weight);
        }
        d.push_back(row);
    }
    // creating pi matrix
    for (int i = 0; i < node; i++)
    {
        vector<int> row;
        for (int j = 0; j < node; j++)
        {
            if (d[i][j] == 0 || d[i][j] == 9999)
                row.push_back(-1); //-1 means nil
            else
                row.push_back(i);
        }
        pi.push_back(row);
    }

    floydWarshall();
    printingPath(2, 0);
}
