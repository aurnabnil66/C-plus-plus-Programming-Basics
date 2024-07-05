#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int A[100][100], s[20], visited[20];
int top = -1;
int num_of_vrtx, starting_vrtx;

void dfs(int v)
{
    for (int i = 0; i < num_of_vrtx; i++)
    {
        if (A[v][i] && !visited[i])
        {
            s[top++] = i;
        }
    }
    if (top != -1)
    {
        visited[s[top]] = 1;
        dfs(s[top--]);
    }
}

int main()
{
    cout << "Enter number of vertices : ";
    cin >> num_of_vrtx;
    cout << "Enter data for adjacency matrix : " << endl;
    for (int i = 0; i < num_of_vrtx; i++)
    {
        for (int j = 0; j < num_of_vrtx; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Enter the value of starting vertex : ";
    cin >> starting_vrtx;
    for (int i = 0; i < num_of_vrtx; i++)
    {
        s[i] = 0;
        visited[i] = 0;
    }
    dfs(starting_vrtx);
    cout << "The reachable nodes are : ";
    for (int i = 0; i < num_of_vrtx; i++)
    {
        if (visited[i])
        {
            cout << i << " ";
        }
    }
}