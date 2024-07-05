#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
struct List
{
    int data;
    struct List *next;
}*front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct List *newnode = (struct List *)malloc(sizeof(struct List));
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }

}

void dequeue()
{
    struct List *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "Underflow";
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
      
}

int size()
{
    struct List *temp;
    temp = front;
    int len = 0;
    while (temp->next != front)
    {
        temp = temp->next;
        len++;
    }
    temp = temp->next;
    len++;
    return len;
}

bool isEmpty()
{
    if (front == NULL)
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
    temp = front;
    if (front == NULL && rear == NULL)
    {
        cout << "Empty";
    }
    else
    {
        while (temp->next != front)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data;
    }

}

int main()
{
    int item, num_of_items, choice, queueInfo, queueSize;
    cout << "Enter number of items : ";
    cin >> num_of_items;

    for (int i = 1; i <= num_of_items; i++)
    {
        cout << "Enter item " << i << " : ";
        cin >> item;
        enqueue(item);
    }
    cout << "Choose any one from below : ";
    cout << "\n1.Press 1 for Enqueue"
         << "\n2.Press 2 to Dequeue"
         << "\n3.Press 3 to see the size"
         << "\n4.Press 4 to see Queue Information"
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
            enqueue(item);
            cout << "Now the queue : ";
            display();
            break;
        case 2:
            dequeue();
            cout << "Now the queue : ";
            display();
            break;
        case 3:
            queueSize = size();
            cout << "Size : " << queueSize;
            break;
        case 4:
            queueInfo = isEmpty();
            if (queueInfo == true)
            {
                cout << "Queue is Empty";
            }
            else
            {
                cout << "Queue has " << size() << " items";
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