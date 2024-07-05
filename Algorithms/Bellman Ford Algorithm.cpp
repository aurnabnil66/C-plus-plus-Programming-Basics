#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int num_of_nodes, num_of_edges;
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;
    cout << "Enter number of edges : ";
    cin >> num_of_edges;
    cout << "\n";
    vector<node> edges;
    for (int i = 0; i < num_of_edges; i++)
    {
        int u,v,wt;
        cout << "Enter starting vertex : ";
        cin >> u;
        cout << "Enter ending vertex : ";
        cin >> v;
        cout << "Enter weight : ";
        cin >> wt;
        edges.push_back(node(u,v,wt));
        cout << "\n";
    }

    int source;
    cout << "Enter source : ";
    cin >> source;

    int inf = 1000000000;
    vector<int> dist(num_of_nodes, inf);

    dist[source] = 0;

    for (int i = 1; i <= num_of_nodes - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }

        }
        
    }

    int x = 0;    // using variable to detect negative cycle
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "There is Negative cycle";
            x = 1;
            break;
        }
    }
    
    if (!x)
    {
        for (int i = 0; i < num_of_nodes; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
        
    }
    
    return 0;
    
}