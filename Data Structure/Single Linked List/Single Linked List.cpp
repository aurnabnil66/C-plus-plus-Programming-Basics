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

int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    create_Node_List(n);
    cout << "Data entered in the list : ";
    display_list();
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
    int count = 0;
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        x = head;
        while (x != NULL)
        {
            count++;
            cout << x -> data << " ";
            x = x -> link;
        }
        cout << "\nNumber of Nodes here : " << count;
    }
    
}