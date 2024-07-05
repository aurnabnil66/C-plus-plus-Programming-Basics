#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *link;
};
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 50;
    head -> link = NULL;

    cout << head-> data << endl;
    cout << head -> link << endl;
    cout << &head << endl;
}
