#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
struct List *head;
void create_list(int n)
{
    head = (struct List *)malloc(sizeof(struct List));
    int i, num;
    cout << "Enter data for Node 1 = ";
    cin >> num;
    head->prev = NULL;
    head->data = num;
    head->next = NULL;

    struct List *temp = head;
    for (i = 2; i <= n; i++)
    {
        struct List *newnode = (struct List *)malloc(sizeof(struct List));
        cout << "Enter data for Node " << i << " = ";
        cin >> num;
        newnode->data = num;
        newnode->prev = NULL;
        newnode->next = NULL;
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void add_at_beginning(int new_data)
{
    struct List *beg_node = (struct List *)malloc(sizeof(struct List));
    beg_node->data = new_data;
    beg_node->prev = NULL;
    beg_node->next = NULL;

    beg_node->next = head;
    head->prev = beg_node;
    head = beg_node;
}
void display_list()
{
    cout << "The list is : ";
    struct List *x = head;
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->next;
    }
}
int main()
{
    head == NULL;
    int n, new_data;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);

    cout << "Enter data for new node : ";
    cin >> new_data;
    add_at_beginning(new_data);

    display_list();
}