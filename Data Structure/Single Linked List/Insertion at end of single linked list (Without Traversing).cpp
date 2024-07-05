#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct List
{
    int data;
    struct List *link;
} *head;

struct List* at_end_node(struct List *ptr, int num);

int main()
{
    struct List *head = (struct List *) malloc(sizeof(struct List));
    head->data = 45;
    head->link = NULL;

    struct List *ptr = head;
    ptr = at_end_node(ptr,55);
    ptr = at_end_node(ptr, 65);                     // These three lines help us to avoid traversing
    ptr = at_end_node(ptr, 75);                     

    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
    
}

struct List* at_end_node(struct List *ptr, int num)
{
    struct List *temp = (struct List *) malloc(sizeof(struct List));           // Time Complexity O(1)
    temp->data = num;
    temp->link = NULL;

    ptr->link = temp;
    return temp;      // return type is struct List*
}