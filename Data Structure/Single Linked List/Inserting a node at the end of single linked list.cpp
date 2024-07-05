#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
} *head;

void create_Node_List(int n);
void display_list();
void end_node(struct List *head,int last_data);

int main()
{
    int n,last_data;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_Node_List(n);
    cout << "Data entered in the list : ";
    display_list();
    cout << "\nEnter data for the last node : ";
    cin >> last_data;
    end_node(head,last_data);
}
void create_Node_List(int n)
{
    head = (struct List *) malloc(sizeof(struct List));
    if(head == NULL)
    {
        cout << "Memory cannot be allocated";
    }
    else
    {
        int num,i;
        cout << "Enter data for Node 1 : ";
        cin >> num;
        head -> data = num;
        head -> link = NULL;
        struct List *temp = head;
        for ( i = 2; i <= n; i++)
        {
            struct List *current = (struct List *) malloc(sizeof(struct List));
            if (current == NULL)
            {
                cout << "Memory cannot be allocated";
                break;
            }
            else
            {
                cout << "Enter data for Node " << i << " : ";
                cin >> num;
                current -> data = num;
                current -> link = NULL;
                temp -> link = current;
                temp = temp -> link;
            }
        }
    }
}
void display_list()
{
    struct List *x;
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        x = head;
        while (x != NULL)
        {
            cout << x -> data << " ";
            x = x -> link;
        }
    }
    
}
void end_node(struct List *head,int last_data)
{
    struct List *ptr,*last,*y;
    ptr = head;
    last = (struct List *)malloc(sizeof(struct List));

    last->data = last_data;
    last->link = NULL;
    
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = last;

    cout << "Updated List : ";
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        y = head;
        while (y != NULL)
        {
            cout << y -> data << " ";
            y = y -> link;
        }
    }

}