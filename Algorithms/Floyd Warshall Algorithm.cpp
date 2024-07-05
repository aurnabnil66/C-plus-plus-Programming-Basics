#include <bits/stdc++.h>
using namespace std;
#define inf 9999
vector<vector<int>> d;
vector<vector<int>> pi;
int num_of_nodes, weight;

void floyd_Warshal()
{
    vector<vector<int>> d_new;
    for (int k = 0; k < num_of_nodes; k++)
    {
        for (int r = 0; r < num_of_nodes; r++)
        {
            vector<int> temp;
            for (int s = 0; s < num_of_nodes; s++)
            {
                temp.push_back(d[r][s]);
            }
            d_new.push_back(temp);
        }

        cout << "After creating new d for k " << k << endl;
        for (int i = 0; i < num_of_nodes; i++)
        {
            for (int j = 0; j < num_of_nodes; j++)
            {
                if (d[i][j] > d[i][k] + d[k][j] && i != j && i != k && j != k)
                {
                    d_new[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }

        // printing new d
        cout << "New d for k " << k << endl;
        for (int i = 0; i < num_of_nodes; i++)
        {
            for (int j = 0; j < num_of_nodes; j++)
            {
                cout << d_new[i][j] << " ";
            }
            cout << endl;
        }

        // printing pi
        cout << "pi for k " << k << endl;
        for (int i = 0; i < num_of_nodes; i++)
        {
            for (int j = 0; j < num_of_nodes; j++)
            {
                cout << pi[i][j] << " ";
            }
            cout << endl;
        }

        // copying d_new to d
        for (int i = 0; i < num_of_nodes; i++)
        {
            for (int j = 0; j < num_of_nodes; j++)
            {
                d[i][j] = d_new[i][j];
            }
        }
    }
}

void print_path(int source, int dest)
{
    if (source == dest)
        cout << dest << "->";
    else if (pi[source][dest] == -1)
        cout << "no path exists" << endl;
    else
        print_path(source, pi[source][dest]);
    cout << dest << "->";
}

int main()
{
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;

    // creating d matrix
    for (int i = 0; i < num_of_nodes; i++)
    {
        vector<int> row;
        for (int j = 0; j < num_of_nodes; j++)
        {
            cin >> weight;
            row.push_back(weight);
        }
        d.push_back(row);
    }

    // creating pi matrix
    for (int i = 0; i < num_of_nodes; i++)
    {
        vector<int> row;
        for (int j = 0; j < num_of_nodes; j++)
        {
            if (d[i][j] == 0 || d[i][j] == inf)
            {
                row.push_back(-1);
            }
            else
            {
                row.push_back(i);
            }
            pi.push_back(row);
        }
    }

    floyd_Warshal();

    print_path(2, 0);
}