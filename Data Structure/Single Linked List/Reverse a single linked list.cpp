#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
};

void add_at_end(struct List *head, int d);
struct List *reverse_list(struct List *head);

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

    cout << "Previous List : ";
    struct List *x = head;
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->link;
    }
    head = reverse_list(head);

    cout << "\nReversed List : ";
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
struct List *reverse_list(struct List *head)
{
    struct List *previous = NULL;
    struct List *next = NULL;
    while(head != NULL)
    {
        next = head->link;
        head->link = previous;
        previous = head;
        head = next;
    }
    head = previous;
    return head;
    
}