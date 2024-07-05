#include <bits/stdc++.h>
using namespace std;
int main()
{
    int source, num_of_nodes, num_of_edges;
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;
    cout << "Enter number of edges : ";
    cin >> num_of_edges;
    cout << "\n";

    vector<pair<int, int>> g[num_of_nodes + 1];  // 1-indexed adjacency list for graph

    int u,v,wt; 
    for (int i = 0; i < num_of_edges; i++)
    {
        cout << "Enter starting vertex : ";
        cin >> u;
        cout << "Enter ending vertex : ";
        cin >> v;
        cout << "Enter weight : ";
        cin >> wt;
        g[u].push_back(make_pair(v,wt));
        g[v].push_back(make_pair(u,wt));
        cout << "\n";
    }
    
    cout << "Enter source : ";
    cin >> source;

    // Dijkstra algorithm starts from here
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>> > pq;  // min-heap;  In pair => (dist, form)
    vector<int> distTo(num_of_nodes + 1, INT_MAX);   // 1-indexed array for shortest paths

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>> :: iterator it;
        for (it = g[prev].begin(); it != g[prev].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
            
        }
        
    }

    cout << "The distances from source " << source << " are : " << endl;
    for (int i = 1; i <= num_of_nodes; i++)
    {
        cout << distTo[i] << " ";
        cout <<"\n";
    }
    return 0;
}