#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
} * head, * ptr;

struct List *at_beg_node(struct List *head, int d);
void create_Node_List(int n);
void display_list();

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_Node_List(n);

    int beg_node_data;
    cout << "Enter data for beginning Node : ";
    cin >> beg_node_data;

    ptr = at_beg_node(head, beg_node_data);

    display_list();
}
void create_Node_List(int n)
{
    head = (struct List *)malloc(sizeof(struct List));
    if (head == NULL)
    {
        cout << "Memory cannot be allocated";
    }
    else
    {
        int num, i;
        cout << "Enter data for Node 1 : ";
        cin >> num;
        head->data = num;
        head->link = NULL;
        struct List *temp = head;
        for (i = 2; i <= n; i++)
        {
            struct List *current = (struct List *)malloc(sizeof(struct List));
            if (current == NULL)
            {
                cout << "Memory cannot be allocated";
                break;
            }
            else
            {
                cout << "Enter data for Node " << i << " : ";
                cin >> num;
                current->data = num;
                current->link = NULL;
                temp->link = current;
                temp = temp->link;
            }
        }
    }
}
struct List *at_beg_node(struct List *head, int d)
{
    ptr = (struct List *)malloc(sizeof(struct List));       // Time Complexity O(1)
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = head;

    return ptr;
}
void display_list()
{
    struct List *x;
    x = ptr;
    cout << "Updated List : ";
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->link;
    }
}