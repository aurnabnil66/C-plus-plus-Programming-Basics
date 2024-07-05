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

void del_from_beginning()
{
    struct List *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "\nEmpty";
    }
    else if (head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
    
}
void del_from_end()
{
    struct List *temp;
    temp = tail;
    if (head == NULL)
    {
        cout << "\nEmpty";
    }
    else if (head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}
void del_from_pos(int pos)
{
    struct List *temp;
    temp = head;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
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