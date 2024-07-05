#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node *create_Tree()
{
    int root_node;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    cout << "Enter root data : ";
    cin >> root_node;
    if (root_node == -1)
    {
        return 0;
    }
    else
    {
        newnode->data = root_node;
        cout << "Enter left child of " << root_node << " : " << endl;
        newnode->left = create_Tree();
        cout << "Enter right child of " << root_node << " : " << endl;
        newnode->right = create_Tree();
        return newnode;
    }
}

void per_order(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        per_order(root->left);
        per_order(root->right);
    }
}

void in_order(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        per_order(root->left);
        cout << root->data << " ";
        per_order(root->right);
    }
    
}

void post_order(node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        per_order(root->left);
        per_order(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    node *root;
    root = create_Tree();
    per_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
    post_order(root);
}
