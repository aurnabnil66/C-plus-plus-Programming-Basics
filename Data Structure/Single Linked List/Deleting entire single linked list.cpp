#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
};
void add_at_end(struct List *head, int d);
struct List *delete_list(struct List *head);
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

    head = delete_list(head);
    
    if (head == NULL)
    {
        cout << "The list was deleted successfully";
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
struct List *delete_list(struct List *head)
{
    struct List *x = head;
    while (x != NULL)
    {
        x = x->link;
        free(head);
        head = x;
    }
    return head;
}