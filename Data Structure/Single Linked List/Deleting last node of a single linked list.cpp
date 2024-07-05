#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
};

void add_at_end(struct List *head, int d);
void del_last_node(struct List *head);

int main()
{
    struct List *head = (struct List *)malloc(sizeof(struct List));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 10);
    add_at_end(head, 67);
    add_at_end(head, 83);
    add_at_end(head, 29);

    del_last_node(head);

    cout << "After deleting last node : ";
    struct List *a = head;
    while (a != NULL)
    {
        cout << a->data << " ";
        a = a->link;
    }
}
void add_at_end(struct List *head, int d)
{
    struct List *ptr = (struct List *)malloc(sizeof(struct List));
    struct List *temp = head;
    ptr->data = d;
    ptr->link = NULL;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = ptr;
}
void del_last_node(struct List *head)
{
    if (head == NULL)
    {
        cout << "The list is empty";
    }
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct List *x = head;
        while (x->link->link != NULL)           // Time Complexity O(n)
        {
            x = x->link;
        }
        free(x->link);     // Constant amount of time
        x->link = NULL;
    }
}