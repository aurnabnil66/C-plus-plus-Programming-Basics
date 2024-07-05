#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
#define MAX 100

int Q[MAX];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if (rear == MAX - 1)
    {
        cout << "Overflow of Queue";
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Q[rear] = item;
        cout << "Data has been enqueued in the queue and the queue is : ";
    }
    else
    {
        rear++;
        Q[rear] = item;
        cout << "Data has been enqueued in the queue and the queue is : ";
    }
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty";
        return 0;
    }
    else
    {
        int temp = Q[front];
        for (int i = front + 1; i <= rear; i++)
        {
            Q[i - 1] = Q[i];
        }
        rear--;
        return temp;
    }
}

int size()
{
    return rear + 1;
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
            for (int i = 0; i <= rear; i++)
            {
                cout << Q[i] << " ";
            }
            break;
        case 2:
            item = dequeue();
            if (item != isEmpty())
            {
                cout << "Dequeued Item : " << item;
            }
            cout << "  Remaining items : ";
            for (int i = 0; i <= rear; i++)
            {
                cout << Q[i] << " ";
            }
            break;
        case 3:
            queueSize = size();
            cout << "Queue Size : " << queueSize;
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