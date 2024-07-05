#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define N 10

int S1[N],S2[N];
int top1 = -1,top2 = -1;
int count = 0;

void enqueue(int x)
{
    push1(x);
    count++;
}

void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "Queue is Empty";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            int a = pop1();
            push1(a);
        }
        int b = pop2();
        cout << "Dequeued Element : " << b;

        count --;
        for (int i = 0; i < count; i++)
        {
            int a = pop2();
            push1(a);
        }
        
    }
    
}

void push1(int data)
{
    if (top1 == N - 1)
    {
        cout << "Overflow";
    }
    else
    {
        top1++;
        S1[top1] = data;
    }
}

int pop1()
{
    return S1[top1--];
}

int pop2()
{
    return S2[top2--];
}

void push2(int data)
{
    if (top2 == N - 1)
    {
        cout << "Overflow";
    }
    else
    {
        top2++;
        S1[top2] = data;
    }
}

void display()
{
    for (int i = 0; i < top1; i++)
    {
        cout << S1[i] << " ";
    }
    
}

int main()
{
    int n,item;
    cout << "Enter number of elements : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter item " << i + 1 << " : ";
        cin >> item;
        enqueue(item);
    }
    dequeue();
    display();
}

