#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct stack_list
{
    int data;
    stack_list *next;
};
struct stack_list *top = NULL;
int num_of_nodes, num_of_edges, starting_vrtx;
int status[20], traverse[20];

void push(int x)
{
    struct stack_list *newnode = (struct stack_list *)malloc(sizeof(struct stack_list));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct stack_list *temp;
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

struct Node
{
    int vrtx;
    Node *next;
};

struct head_list
{
    Node *head;
};
head_list *adj_list[20];

void add_node(int s, int d)
{
    Node *source;
    Node *destaination;
    Node *temp;

    if (adj_list[s]->head == NULL)
    {
        source = new Node();
        source->vrtx = s;
        source->next = NULL;
        adj_list[s]->head = source;
    }
    destaination = new Node();
    destaination->vrtx = d;
    destaination->next = NULL;
    temp = adj_list[s]->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = destaination;
}

void dfs(int v)
{
    push(v);
    status[v] = 2;
    int t = 0;
    int source_vrtx;
    Node *temp;
    while (!isEmpty())
    {
        source_vrtx = pop();
        status[source_vrtx] = 3;
        traverse[t] = source_vrtx;
        t++;
        temp = adj_list[source_vrtx]->head;
        while (temp != NULL)
        {
            if (status[temp->vrtx] == 1)
            {
                push(temp->vrtx);
                status[temp->vrtx] = 2;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    cout << "Enter number of nodes : ";
    cin >> num_of_nodes;

    int choice, source, destinantion;
    for (int i = 0; i < num_of_nodes; i++)
    {
        adj_list[i] = new head_list();
        adj_list[i]->head = NULL;
    }
    for (int i = 0;; i++)
    {
        cout << "Enter 1 to add node : ";
        cin >> choice;
        if (choice == 1)
        {
            break;
        }
        else
        {
            cout << "Enter source : ";
            cin >> source;
            cout << "Enter destinantion : ";
            cin >> destinantion;
            add_node(source, destinantion);
        }
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
