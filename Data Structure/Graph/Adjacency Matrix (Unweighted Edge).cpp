#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int graph[200][200];
int weight = 1;

int main()
{
    int num_of_nodes,num_of_edges;
    
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;
    
    cout << "Enter number of edges : ";
    cin >> num_of_edges;

    int source,destination;
    
    for (int i = 1; i <= num_of_edges; i++)
    {
        cout << "Enter data for Edge " << i << " : \n";
        cout << "Enter Source : ";
        cin >> source;
        cout << "Enter Destination : ";
        cin >> destination;
        cout << endl;
        
        graph[source][destination] = weight;
        graph[destination][source] = weight;
    }
    
    cout << "The Adjacency Matrix Will be : " << endl;
    for (int i = 1; i <= num_of_nodes; i++)
    {
        for (int j = 1; j <= num_of_nodes; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}