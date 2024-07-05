#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
};
void add_at_end(struct List *head, int d);
struct List *del_first_node(struct List *head);
int main()
{
    struct List *head = (struct List *)malloc(sizeof(struct List));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 10);

    head = del_first_node(head);

    cout << "The list will be : ";
    struct List *x = head;
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->link;
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
struct List *del_first_node(struct List *head)
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        struct List *temp = head;            // Time Complexity O(1)
        head = head->link;                   // or head = x->link, then we don't need to return
        free(temp);
        temp = NULL;
    }
    return head;
}