#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
};
void add_at_end(struct List *head, int d);
void del_certain_node(struct List **head, int p);
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

    int pos;
    cout << "Enter position : ";
    cin >> pos;
    del_certain_node(&head, pos);

    cout << "After deleting desired node : ";
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
void del_certain_node(struct List **head, int p)
{
    struct List *current = *head;
    struct List *previous = *head;
    if (*head == NULL)
    {
        cout << "The list is empty";
    }
    else if (p == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (p != 1)
        {
            previous = current;
            current = current->link;
            p--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}