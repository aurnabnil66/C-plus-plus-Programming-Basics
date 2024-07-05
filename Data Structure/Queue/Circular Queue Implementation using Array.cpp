#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
#define max 10

int Q[max];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        Q[rear] = x;
        cout << "Data has been enqueued in the queue and the queue is : ";
    }
    else if ((rear + 1) % max == front)
    {
        cout << "Queue is full";
    }
    else
    {
        rear = (rear + 1) % max;
        Q[rear] = x;
        cout << "Data has been enqueued in the queue and the queue is : ";
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout << Q[front];
        front = (front + 1) % max;
    }
}

int size()
{
    return rear;
}

bool isEmpty()
{
    if (rear == -1)
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
    int i = front;
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
    }
    else
    {
        while (i != rear)
        {
            cout << Q[i] << " ";
            i = (i + 1) % max;
        }
        cout << Q[i] << " ";
    }
}

int main()
{
    int choice, item, queueInfo, queueSize;

    cout << "Choose any one from below : ";
    cout << "\n1.Press 1 for Enqueue"
         << "\n2.Press 2 for Dequeue"
         << "\n3.Press 3 to see the size"
         << "\n4.Press 4 to see Queue Information"
         << "\nPress 5 to exit";
    while (true)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter item to insert : ";
            cin >> item;
            enqueue(item);
            display();
            break;
        case 2:
            cout << "Dequeued item : ";
            dequeue();
            cout << "\nThe Queue : ";
            display();
            break;
        case 3:
            queueSize = size();
            cout << "Size of the queue : " << queueSize;
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
            break;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
}
