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
void delete_node(int choice)
{
    if (choice == 0)
    {
        struct List *temp;
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        temp = NULL;
    }
    else if (choice == -1)
    {
        struct List *ptr;
        ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
    else
    {
        int pos = choice;
        int i = 1;
        struct List *x = head;
        while (i < pos)
        {
            x = x->next;
            i++;
        }
        x->prev->next = x->next;
        x->next->prev = x->prev;
        free(x);
        x = NULL;
    }
}
void display_list()
{
    cout << "The list is : ";
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
    int n, choice;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_list(n);
    display_list();

    cout << endl;
    cout << "\n1.Press 0 to delete from beginning"
         << "\n2.Press -1 to delete from end"
         << "\n3.Press the position to delete particularly";
    cout << "\nEnter choice : ";
    cin >> choice;
    if (choice == 0)
    {
        delete_node(choice);
        display_list();
    }
    else if(choice == -1)
    {
        delete_node(choice);
        display_list();
    }
    else
    {
        delete_node(choice);
        display_list();
    }

    
}