#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
bool visited[100];

void dfs(int source)
{
    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++)
    {
        int next = graph[source][i];
        if (visited[next] == 0)
        {
            dfs(next);
        }
    }
}

int main()
{
    int nodes, edges, start_point, end_point;
    cout << "Enter number of nodes : ";
    cin >> nodes;
    cout << "Enter number of edges : ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter start point : ";
        cin >> start_point;
        cout << "Enter end point : ";
        cin >> end_point;

        graph[start_point].push_back(end_point);
        graph[end_point].push_back(start_point);
    }

    dfs(0);

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 1)
        {
            cout << "Node " << i << " is visited" << endl;
        }
        else
        {
            cout << "Node " << i << " is not visited" << endl;
        }
    }

    return 0;
}