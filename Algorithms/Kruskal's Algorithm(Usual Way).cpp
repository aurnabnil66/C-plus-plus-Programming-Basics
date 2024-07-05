#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[100];
vector<pair<int, int>> mst[100];
pair<int, int> sorted_edge[30];

int u, v, w, num_of_edges, num_of_nodes, s = 0, d = 0;
bool check_edge[20][20];
int is_part_Of_mst[20];
int dist[20];

priority_queue<int, vector<int>, greater<int>> sorted_weight;

void find_source_destination(int x)
{
    for (int i = 0; i < num_of_nodes; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j].second == x && check_edge[i][graph[i][j].first] == 0)
            {
                sorted_edge[s].first = i;
                sorted_edge[s].second = graph[i][j].first;
                s++;
                check_edge[i][graph[i][j].first] = 1;
            }
        }
    }
}

void kruskal()
{
    for (int i = 0; i < num_of_nodes; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            sorted_weight.push(graph[i][j].second);
        }
    }
    while (!sorted_weight.empty())
    {
        int x;
        x = sorted_weight.top();
        find_source_destination(x);
        dist[d++] = x;
        sorted_weight.pop();
    }
    for (int i = 0; i < s; i++)
    {
        cout << sorted_edge[i].first << " " << sorted_edge[i].second << endl;
    }
    for (int i = 0; i < s; i++)
    {
        if (is_part_Of_mst[sorted_edge[i].first] == -1)
        {
            mst[sorted_edge[i].first].push_back(make_pair(sorted_edge[i].second, dist[i]));
            is_part_Of_mst[sorted_edge[i].first] = sorted_edge[i].second;
        }
    }

    cout << "\nMST is : " << endl;
    for (int i = 0; i < num_of_nodes; i++)
    {
        for (int j = 0; j < mst[i].size(); j++)
        {
            cout << i << " is connected to " << mst[i][j].first << " and weight is " << mst[i][j].second << endl;
        }
        
    }
    
}
int main()
{
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;
    cout << "Enter number of edges : ";
    cin >> num_of_edges;
    cout << "\n";
    for (int i = 0; i < num_of_edges; i++)
    {
        cout << "Enter starting vertex : ";
        cin >> u;
        cout << "Enter ending vertex : ";
        cin >> v;
        cout << "Enter weight : ";
        cin >> w;
        graph[u].push_back(make_pair(v, w));
        cout << "\n";
    }

    for (int i = 0; i < num_of_nodes; i++)
    {
        is_part_Of_mst[i] = -1;
    }
    kruskal();
}