#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
struct List
{
    int data;
    struct List *next;
};
struct List *top = NULL;
int graph[20][20] = {0, 0}, num_of_nodes, num_of_edges, starting_vrtx;
int status[20], traverse[20];

void push(int x)
{
    struct List *newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct List *temp;
    temp = top;
    if (top == NULL)
    {
        cout << "Underflow";
        return 0;
    }
    else
    {
        top = top->next;
        int a = temp->data;
        free(temp);
        return a;
    }
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs(int v)
{
    push(v);
    status[v] = 2;
    int t = 0;
    int source_vrtx;
    while (!isEmpty())
    {
        source_vrtx = pop();
        status[source_vrtx] = 3;
        traverse[t] = source_vrtx;
        t++;
        for (int i = 0; i < num_of_nodes; i++)
        {
            if (graph[source_vrtx][i] != 0 && status[i] == 1)
            {
                push(i);
                status[i] = 2;
            }
        }
    }
}

void display_matrix()
{
    cout << "The Adjacency Matrix is : " << endl;
    for (int i = 0; i < num_of_nodes; i++)
    {
        for (int j = 0; j < num_of_nodes; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, source, destination, weight;
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;
    cout << "Enter number of edges : ";
    cin >> num_of_edges;

    cout << "Choose Graph Option : ";
    cout << "\n1.Undirected unweighted graph"
         << "\n2.Directed unweighted graph "
         << "\n3.Undirected weighted graph "
         << "\n4.Directed weighted graph ";
    cout << "\nEnter choice : ";
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < num_of_edges; i++)
        {
            cout << "Enter source node : ";
            cin >> source;
            cout << "Enter destination node : ";
            cin >> destination;
            graph[source][destination] = 1;
            graph[destination][source] = 1;
        }
        display_matrix();
    }
    if (choice == 2)
    {
        for (int i = 0; i < num_of_edges; i++)
        {
            cout << "Enter source node : ";
            cin >> source;
            cout << "Enter destination node : ";
            cin >> destination;
            graph[source][destination] = 1;
        }
        display_matrix();
    }
    if (choice == 3)
    {
        for (int i = 0; i < num_of_edges; i++)
        {
            cout << "Enter source node : ";
            cin >> source;
            cout << "Enter destination node : ";
            cin >> destination;
            cout << "Enter weight : ";
            cin >> weight;
            graph[source][destination] = weight;
            graph[destination][source] = weight;
        }
        display_matrix();
    }
    if (choice == 4)
    {
        for (int i = 0; i < num_of_edges; i++)
        {
            cout << "Enter source node : ";
            cin >> source;
            cout << "Enter destination node : ";
            cin >> destination;
            cout << "Enter weight : ";
            cin >> weight;
            graph[source][destination] = weight;
        }
        display_matrix();
    }

    cout << "Enter starting vertex : ";
    cin >> starting_vrtx;
    for (int i = 0; i < num_of_nodes; i++)
    {
        status[i] = 1;
        traverse[i] = -1;
    }
    dfs(starting_vrtx);

    cout << "Visited Path : ";
    for (int i = 0; i < num_of_nodes; i++)
    {
        if (traverse[i] != -1)
        {
            cout << traverse[i] << " ";
        }
    }
}