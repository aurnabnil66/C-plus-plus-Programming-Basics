#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num_of_nodes, num_of_edges;
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;
    cout << "Enter number of edges : ";
    cin >> num_of_edges;
    cout << "\n";
    vector<pair<int, int>> adj[num_of_nodes];

    int u,v,wt;
    for (int i = 0; i < num_of_edges; i++)
    {
        cout << "Enter starting vertex : ";
        cin >> u;
        cout << "Enter ending vertex : ";
        cin >> v;
        cout << "Enter weight : ";
        cin >> wt;

        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    int parent[num_of_nodes];        // parent array will hold the nodes of final spanning tree
    int key[num_of_nodes];           // key array will hold the minimum weights
    bool mstSet[num_of_nodes];      // mstSet will confirm whether the node is a part of MST or not 

    for (int i = 0; i < num_of_nodes; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});    // pq.push({value stored in that index, index number of minimum weight})

    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken.
    // as we are using heap here so it will be O(nlogn)

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
            
        }
        
    }

    for (int i = 0; i < num_of_nodes; i++)
    {
        cout << parent[i] << " - " << i << endl;
    }
    return 0;
    
    
    // trying the following case: 
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
}