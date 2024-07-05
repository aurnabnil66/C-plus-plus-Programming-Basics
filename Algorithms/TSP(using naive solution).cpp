#include<bits/stdc++.h>
using namespace std;
#define V 4
int travellingSalesman(int graph[][V], int s)
{
    // store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
    {
        if (i != s)
        {
            vertex.push_back(i);
        }
        
    }
    
    // store minimum weight hamiltonian cycle
    int min_path = INT_MAX;
    do
    {
        // store current path weight(cost)
        int curr_path_weight = 0;
        
        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            curr_path_weight += graph[k][vertex[i]];
            k = vertex[i];
        }
        curr_path_weight += graph[k][s];

        // update minimum
        min_path = min(min_path,curr_path_weight);
        
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
    

}
int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 5, 0, 9, 10 },
                       { 6, 13, 0, 12 },
                       { 8, 8, 9, 0 } };
    
    int s = 0;

    int result = travellingSalesman(graph,s);
    cout << "Minimum cost : " << result;

    return 0;
}