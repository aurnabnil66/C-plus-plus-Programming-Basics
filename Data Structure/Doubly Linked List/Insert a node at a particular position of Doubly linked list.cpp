#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
struct List *head;
void create_list(int n)
{
    head = (struct List *)malloc(sizeof(struct List));
    int i, num;
    cout << "Enter data for Node 1 = ";
    cin >> num;
    head->prev = NULL;
    head->data = num;
    head->next = NULL;

    struct List *temp = head;
    for (i = 2; i <= n; i++)
    {
        struct List *newnode = (struct List *)malloc(sizeof(struct List));
        cout << "Enter data for Node " << i << " = ";
        cin >> num;
        newnode->data = num;
        newnode->prev = NULL;
        newnode->next = NULL;
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void add_at_pos(int new_data, int choice)
{
    struct List *newnode, *ptr;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->prev = NULL;
    newnode->data = new_data;
    newnode->next = NULL;
    if (choice == 0)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else if (choice == -1)
    {
        struct List *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
    else
    {
        int pos = choice;
        int i = 1;
        int len = 0;
        ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            len++;
        }
        if (pos < len)
        {
            ptr = head;
            while (i < pos - 1)
            {
                ptr = ptr->next;
                i++;
            }
            newnode->prev = ptr;
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        else
        {
            cout << "Invalid Position";
        }
    }
}
void display_list()
{
    cout << "\nThe list is : ";
    struct List *x = head;
    while (x != NULL)
    {
        cout << x->data << " ";
        x = x->next;
    }
}
int main()
{
    head == NULL;
    int n, new_data, choice;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);
    display_list();

    cout << "\nEnter data for new Node : ";
    cin >> new_data;
    cout << endl;
    cout << "1.Press 0 to add at beginning"
         << "\n2.Press -1 to add at end"
         << "\n3.Press the position to add at paricular place";
    cout << "\nEnter choice : ";
    cin >> choice;
    if (choice == 0)
    {
        add_at_pos(new_data, choice);
        display_list();
    }
    else if (choice == -1)
    {
        add_at_pos(new_data, choice);
        display_list();
    }
    else
    {
        add_at_pos(new_data, choice);
        display_list();
    }

    
}