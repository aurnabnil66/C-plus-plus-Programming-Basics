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

void reverse_list()
{
    struct List *prev2, *next2, *temp;
    temp = tail->next;
    next2 = temp->next;
    if (tail == NULL)
        cout << "List is empty" << endl;
    else
    {
        while (temp != tail)
        {
            prev2 = temp;
            temp = next2;
            next2 = temp->next;
            temp->next = prev2;
        }
        next2->next = tail;
        tail = next2;
    }
}

void display_list()
{
    struct List *x = tail->next;
   
    while (x->next != tail->next)
    {
        cout << x->data << " ";
        x = x->next;
    }
    cout << x->data;
}

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);
    cout << "The list is : ";
    display_list();

    cout << "\nThe list in reversed order : ";
    reverse_list();
    display_list();
}