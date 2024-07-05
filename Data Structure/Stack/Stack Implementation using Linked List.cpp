#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
struct List
{
    int data;
    List *next;
} *top = NULL;

void push(int x)
{
    struct List *newnode;
    newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct List *temp;
    temp = top;
    if (top == NULL)
    {
        cout << "Underflow";
    }
    else
    {
        cout << "Popped Item : " << top->data;
        top = temp->next;
        free(temp);
        return 0;
    }
}

int size()
{
    struct List *temp;
    temp = top;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display()
{
    struct List *temp;
    temp = top;
    if (top == NULL)
    {
        cout << "Empty";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

int main()
{
    int item, num_of_items, choice, stackinfo, stacksize;
    cout << "Enter number of items : ";
    cin >> num_of_items;

    for (int i = 1; i <= num_of_items; i++)
    {
        cout << "Enter item " << i << " : ";
        cin >> item;
        push(item);
    }
    cout << "Choose any one from below : ";
    cout << "\n1.Press 1 for Push"
         << "\n2.Press 2 to Pop"
         << "\n3.Press 3 to see the size"
         << "\n4.Press 4 to see stack information"
         << "\n5.Press 5 to exit";

    while (true)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter new item : ";
            cin >> item;
            push(item);
            cout << "Now the stack : ";
            display();
            break;
        case 2:
            pop();
            cout << "\nNow the stack : ";
            display();
            break;
        case 3:
            stacksize = size();
            cout << "Size : " << stacksize;
            break;
        case 4:
            stackinfo = isEmpty();
            if (stackinfo == true)
            {
                cout << "Stack is Empty";
            }
            else
            {
                cout << "Stack has " << size() << " items";
            }
            break;
        case 5:
            return 0;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
}