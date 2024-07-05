#include <bits/stdc++.h>
using namespace std;
vector<int> graph_test[10];
int main()
{
    // graph input variables
    int num_of_edges = 3;
    int num_of_nodes = 4;
    int start_point, end_point;

    for (int i = 1; i <= num_of_edges; i++)
    {
        cout << "Edge - " << i << " : " << endl;
        cout << "Start point : ";
        cin >> start_point;
        cout << "End point : ";
        cin >> end_point;

        // for the connection between two nodes
        graph_test[start_point].push_back(end_point);
    }

    // testing purpose only
    cout << graph_test[1].size() << endl << "\n";

    for (int i = 1; i <= num_of_nodes; i++)
    {
        cout << "Node - " << i << " connected to " << endl;
        for (int j = 0; j < graph_test[i].size(); j++)
        {
            cout << graph_test[i][j] << endl;
        }
    }
}