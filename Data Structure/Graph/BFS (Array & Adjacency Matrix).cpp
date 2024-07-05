#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int A[100][100], q[20], visited[20];
int front = 0, rear = -1;
int num_of_vrtx,starting_vrtx;

void bfs(int v)
{
    for (int i = 0; i < num_of_vrtx; i++)
    {
        if (A[v][i] && !visited[i])
        {
            q[rear++] = i;
        }
    }
    if (front <= rear)
    {
        visited[q[front]] = 1;
        bfs(q[front++]);
    }

}

int main()
{
    cout << "Enter number of vertices : ";
    cin >> num_of_vrtx;
    cout << "Enter data for adjacency matrix : " << endl;
    for (int i = 0; i < num_of_vrtx; i++)
    {
        for (int j = 0; j < num_of_vrtx; j++)
        {
            cin >> A[i][j];
        }
        
    }
    cout << "Enter the value of starting vertex : ";
    cin >> starting_vrtx;
    for (int i = 0; i < num_of_vrtx; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    bfs(starting_vrtx);
    cout << "The reachable nodes are : ";
    for (int i = 0; i < num_of_vrtx; i++)
    {
        if (visited[i])
        {
            cout << i << " ";
        }
        
    }
    
}