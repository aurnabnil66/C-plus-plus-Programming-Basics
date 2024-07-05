#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[105];
bool visited[105];

vector<int> result;

void dfs(int source)
{

    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++)
    {
        int next = graph[source][i].first;
        if (visited[next] == 0)
            dfs(next);
    }

    result.push_back(source);
}

void cycle_exist(int source)
{

}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    reverse(result.begin(), result.end());
    cout << "Topological order: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    cout << "\n";

    for (int i = 1; i <= nodes; i++)
    {
        visited[i] == 1
        if (visited[] ==)
        {
           
        }
    }

    cout << "Enter source : " << endl;
    int sourceForPath;
    cin >> sourceForPath;
    int dist[nodes], parent[nodes];

    for (int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = 9999;
    }

    dist[sourceForPath] = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (dist[i] != INT_MAX)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {

                if (dist[i] + graph[i][j].second < dist[graph[i][j].first])
                {
                    dist[graph[i][j].first] = dist[i] + graph[i][j].second;
                    parent[graph[i][j].first] = i;
                }
            }
        }
    }

    cout << "cost  " << endl;
    for (int i = 0; i < nodes; i++)
    {
        cout << dist[i] << endl;
    }
    cout << "path" << endl;
    int parentNode;

    for (int i = 0; i < nodes; i++)
    {
        parentNode = parent[i];
        if (parent[i] == 9999 && i != sourceForPath)
            cout << "No shortest path from " << i << "to " << sourceForPath << endl;
        else if (i == sourceForPath)
            cout << i << " Is source itself" << endl;

        else
        {
            cout << i;
            while (parentNode != sourceForPath)
            {
                cout << " <-" << parentNode;
                parentNode = parent[parentNode];
            }
            cout << " <-" << parentNode << endl;
        }
    }

    return 0;
}
