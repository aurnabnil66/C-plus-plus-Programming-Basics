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

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

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
        int u, v, wt;
        cout << "Enter starting vertex : ";
        cin >> u;
        cout << "Enter ending vertex : ";
        cin >> v;
        cout << "Enter weight : ";
        cin >> wt;
        edges.push_back(node(u, v, wt));
        cout << "\n";
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(num_of_nodes);
    for (int i = 0; i < num_of_nodes; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(num_of_nodes, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    cout << cost << endl;
    for (auto it : mst)
    {
        cout << it.first << " - " << it.second << endl;
    }

    return 0;
}