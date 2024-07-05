#include<bits/stdc++.h>
using namespace std;
#define MAX 100
vector<int> graph[MAX];
bool visited[MAX];
int distance[MAX];

void bfs(int source)
{
    queue<int> Q;
    
    //initialization
    visited[source] = 1;
    distance[source] = 0;
    Q.push(source);

    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if (visited[next] == 0)  // if unvisited
            {
                visited[next] = 1;  // then visit
                distance[next] = distance[node] + 1;  // update distance
                Q.push(next);  // push in the queue
            }
            
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

    int source;
    cout << "Enter source : ";
    cin >> source;
    bfs(source);

    cout << "From Node " << source << "......." << endl;
    for (int i = 1; i <= nodes; i++)
    {
        cout << "Distance of" << i << "is" << distance[i] << endl;
    }
    

    return 0;
} 