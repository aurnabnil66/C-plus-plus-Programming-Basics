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
    int i,num;
    cout << "Enter data for Node 1 = ";
    cin >> num;
    head->prev = NULL;
    head->data = num;
    head->next = NULL;

    struct List *temp = head;
    for ( i = 2; i <= n; i++)
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
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    create_list(n);
    display_list();
}