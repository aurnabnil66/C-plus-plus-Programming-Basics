#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
bool visited[100];
vector<int> result;

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
    // All children explored and now can do this :

    result.push_back(source);
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
    }
    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
        
    }

    reverse(result.begin(), result.end());  // reversing the result vector to get the correct result
    
    cout << "Topological Order : ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    return 0;
}