#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
};

void add_at_end(struct List *head, int d);
void add_at_pos(struct List *head, int cer_data,int pos);

int main()
{
    struct List *head = (struct List *)malloc(sizeof(struct List));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 10);

    int cer_data, pos;
    cout << "Enter data : ";
    cin >>cer_data;
    cout << "Enter position : ";
    cin >> pos;

    add_at_pos(head,cer_data,pos);

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
void add_at_pos(struct List *head, int cer_data,int pos)
{
    struct List *ptr2 = head;
    struct List *certain = (struct List *)malloc(sizeof(struct List));
    certain->data = cer_data;
    certain->link = NULL;

    pos--;
    while (pos != 1)              // Time Complexity O(n)
    {
        ptr2 = ptr2->link;
        pos--;
    }
    certain->link = ptr2->link;
    ptr2->link = certain;
}
