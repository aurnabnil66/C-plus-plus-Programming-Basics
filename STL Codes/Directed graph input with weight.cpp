#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> graph_test_pair[10];
// or
/*
typedef pair<int, int> c_pair;
vector<c_pair> graph_test_pair[10];
*/
int main()
{
    int num_of_edges = 3;
    int num_of_nodes = 4;
    int start_point, end_point, weight;

    for (int i = 1; i <= num_of_edges; i++)
    {
        cout << "Edge - " << i << " : " << endl;
        cout << "Start point : ";
        cin >> start_point;
        cout << "End point : ";
        cin >> end_point;
        cout << "Enter weight : ";
        cin >> weight;

        // for the connection between two nodes with weight
        graph_test_pair[start_point].push_back(make_pair(end_point, weight));
    }

    // for test purpose only
    cout <<"\nTest Output : " << endl;
    cout << graph_test_pair[1].size() << endl;
    cout << "Sample Edge : " << graph_test_pair[1][1].first << endl;
    cout << "Sample Weight : " << graph_test_pair[1][1].second << endl;

    // printing graph with weight
     for (int i = 1; i <= num_of_nodes; i++)
    {
        cout << "Node - " << i << " connected to" << endl;
        for (int j = 0; j < graph_test_pair[i].size(); j++)
        {
            cout << graph_test_pair[i][j].first << endl;
            cout << graph_test_pair[i][j].second << endl;
        }
    } 

    return 0;

}