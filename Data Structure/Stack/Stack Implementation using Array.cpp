#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
#define MAX 100

int S[MAX];
int top = -1;

void push(int item)
{
    if (top == MAX - 1)
    {
        cout << "Overflow";
    }
    else
    {
        top++;
        S[top] = item;
        cout << "Data has been pushed in the stack and the stack is : ";
    }
}

int pop()
{
    int item;
    if (top == -1)
    {
        cout << "Underflow";
        return 0;
    }
    else
    {
        return S[top--];
    }
}

void peek()
{
    int item;
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        item = S[top];
        cout << "Top item : " << item;
    }
}

int size()
{
    return top + 1;
}

bool isEmpty()
{
    if (top == -1)
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
    int choice, item, stackInfo, stackSize;

    cout << "Choose any one from below : ";
    cout << "\n1.Press 1 for Push"
         << "\n2.Press 2 for Pop"
         << "\n3.Press 3 to see the size"
         << "\n4.Press 4 Stack Information"
         << "\n5.Press 5 to Peek"
         << "\nPress 6 to exit";

    while (true)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter item to insert : ";
            cin >> item;
            push(item);
            for (int i = 0; i <= top; i++)
            {
                cout << S[i] << " ";
            }
            break;
        case 2:
            item = pop();
            if (item != isEmpty())
            {
                cout << "Popped Item : " << item;
            }
            cout << "  Remaining items : ";
            for (int i = 0; i <= top; i++)
            {
                cout << S[i] << " ";
            }
            break;
        case 3:
            stackSize = size();
            cout << "Stack Size : " << stackSize;
            break;
        case 4:
            stackInfo = isEmpty();
            if (stackInfo == true)
            {
                cout << "Stack is Empty";
            }
            else
            {
                cout << "Stack has " << size() << " items";
            }
            break;
        case 5:
            peek();
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "\nInvalid Choice";
            break;
        }
    }
}
