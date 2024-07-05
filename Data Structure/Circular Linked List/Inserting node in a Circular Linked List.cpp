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

void insert_at_beginning(int new_data)
{
    struct List *newnode;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = new_data;
    newnode->next = NULL;

    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insert_at_end(int new_data)
{
    struct List *newnode;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = new_data;
    newnode->next = NULL;

    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insert_at_pos(int pos, int new_data)
{
    struct List *newnode, *temp;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = new_data;
    newnode->next = NULL;

    int i = 1;
    temp = tail->next;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

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
    cout << x->data;
}

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);
    display_list();

    int choice, new_data, pos;
    cout << endl;
    cout << "\n1.Press 1 to add node at beginning"
         << "\n2.Press 2 to add node at end"
         << "\n3.Press 3 to add at a particular position"
         << "\n4.Press 4 to end the program";
    cout << endl;

    while (true)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to insert : ";
            cin >> new_data;
            insert_at_beginning(new_data);
            display_list();
            break;
        case 2:
            cout << "Enter data to insert : ";
            cin >> new_data;
            insert_at_end(new_data);
            display_list();
            break;
        case 3:
            cout << "Enter data to insert : ";
            cin >> new_data;
            cout << "Enter postion : ";
            cin >> pos;
            insert_at_pos(pos, new_data);
            display_list();
            break;
        case 4:
            return 0;
        default:
            cout << "\nInvalid choice";
            break;
        }
    }
}
