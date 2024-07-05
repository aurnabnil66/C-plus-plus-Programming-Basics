#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

int flag = 1;

struct Node *create_node(int x)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << "   ";
        inOrder(root->right);
    }
}

struct Node *insert(struct Node *node, int value)
{
    if (node == NULL)
    {
        return create_node(value);
    }
    if (value == node->data)
    {
        cout << "This data has already been inserted";
        flag = 0;
    }
    else if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }
    return node;
}

int main()
{
    int item;
    struct Node *root = NULL;
    root = insert(root, 27);
    insert(root, 10);
    insert(root, 12);
    insert(root, 24);
    insert(root, 3);
    insert(root, 8);
    insert(root, 80);

    cout << "The tree is : \n";
    inOrder(root);

    cout << "\nEnter data to be inserted : ";
    cin >> item;
    insert(root, item);

    if (flag == 1)
    {
        inOrder(root);
    }
    return 0;
}
