#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
struct Node *root;

struct Node *create_node(int x)
{

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = x;
    newnode->parent = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void left_child(struct Node *temp, struct Node *child)  // temp = root, child = newnode
{
    temp->left = child;
    if (child != NULL)
    {
        child->parent = temp;
    }
    
}

void right_child(struct Node *temp, struct Node *child)
{
    temp->right = child;
    if (child != NULL)
    {
        child->parent = temp;
    }
    
}

struct Node *insert(struct Node *temp, struct Node *node)  // temp = root, node = the node to be inserted
{
    struct Node *parent_node; 
    struct Node *current_node;
    if (temp == NULL)                        
    {
        temp = node;
        return temp;
    }
    parent_node = NULL;
    current_node = temp; 
    while (current_node != NULL)
    {
        parent_node = current_node;
        if (node->data < current_node->data)
        {
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }
    if (node->data < parent_node->data)
    {
        left_child(parent_node, node);
    }
    else
    {
        right_child(parent_node, node);
    }
    return temp;

}

struct Node *create_BST()
{
    Node *temp, *n;
    
    int A[] = {2,4,8,9,10,11,5,3,6,7};
    temp = create_node(1);
    for (int i = 0; i < 8; i++)
    {
        n = create_node(A[i]);
        root = insert(temp,n);
    }
    
}

void inOrder(struct Node *curr)
{
    if (root == NULL)
    {
        cout << "Empty";
        return;
    }
    if(curr->left != NULL)
    {
        inOrder(curr->left);
    }
    cout << curr->data << "  ";
    if(curr->right != NULL)
    {
        inOrder(curr->right);
    }
}

int main()
{
    root = create_BST();
    inOrder(root);

    return 0;
}
