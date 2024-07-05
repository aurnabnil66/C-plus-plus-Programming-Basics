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

void del_from_beginning()
{
    struct List *temp;
    temp = tail->next;
    if (tail == 0)
    {
        cout << "\nList is Empty" << endl;
    }
    else if (temp == temp->next)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

void del_from_end()
{
    struct List *temp, *prev;
    temp = tail->next;
    if (tail == 0)
    {
        cout << "\nList is Empty" << endl;
    }
    else if (temp == temp->next)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != tail->next)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(temp);
    }
}

void del_from_pos(int pos)
{
    struct List *temp, *next2;
    int i = 1;
    temp = tail->next;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    next2 = temp->next;
    temp->next = next2->next;
    free(next2);
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

    cout << endl;
    cout << "\n1.Press 1 for deleting from beginning"
         << "\n2.Press 2 for deleting from end"
         << "\n3.Press 3 for deleting from particular position"
         << "\n4.Press 4 to exit the program";

    int choice, pos;

    while (true)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            del_from_beginning();
            display_list();
            break;
        case 2:
            del_from_end();
            display_list();
            break;
        case 3:
            cout << "Enter position : ";
            cin >> pos;
            del_from_pos(pos);
            display_list();
            break;
        case 4:
            return 0;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
}