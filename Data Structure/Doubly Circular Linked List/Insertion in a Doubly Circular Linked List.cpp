#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *next;
    struct List *prev;
} * head, *tail;

void create_list(int n)
{
    int num;
    head = NULL;
    for (int i = 1; i <= n; i++)
    {
        cout << "Enter data for node " << i << " : ";
        cin >> num;
        struct List *newnode;
        newnode = (struct List *)malloc(sizeof(struct List));
        newnode->data = num;

        if (head == NULL)
        {
            head = tail = newnode;
            head->next = head; // tail->next = tail;        // newnode->next = newnode;
            head->prev = head; //  tail->prev = tail;       //  newnode->prev = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
    }
}

void insert_at_beginning(int new_data)
{

    struct List *newnode;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = new_data;

    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = head;
        newnode->prev = tail;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void insert_at_end(int new_data)
{
    struct List *newnode;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = new_data;

    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = head;
        newnode->prev = tail;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
}

void insert_at_pos(int pos, int new_data)
{
    struct List *newnode, *temp;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = new_data;

    int i = 1;
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void display_list()
{
    struct List *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        while (temp != tail)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
    }
}

int main()
{
    int n, choice, new_data, pos;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);

    cout << endl;
    cout << "\n1.Press 1 to add node at beginning"
         << "\n2.Press 2 to add node at end"
         << "\n3.Press 3 to add at a particular position"
         << "\n4.Press 4 to end the program";

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