#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *next;
} * head, *tail;

void create_list(int n)
{
    int num;
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data for node " << i << " : ";
        cin >> num;
        struct List *newnode = (struct List *)malloc(sizeof(struct List));
        newnode->data = num;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
    }
}

void display_list()
{
    struct List *x = tail->next;
    cout << "The list is : ";
    while (x->next != tail->next)
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << x->data << " ";
}

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);

    display_list();
}
