/*DON'T DELETE ANY GIVEN COMMENT,
    WRITE YOUR CODE FROM THE NEXT LINE
    OF THE GIVEN COMMENT*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head;

void createList(int arr[], int len)
{
    /*Create a Linked list using the global head and supplied array*/

    head = (struct Node *)malloc(sizeof(struct Node));

    head->data = arr[0];
    head->next = NULL;
    struct Node *temp = head;
    for (int i = 1; i < len; i++)
    {
        struct Node *current = (struct Node *)malloc(sizeof(struct Node));

        current->data = arr[i];
        current->next = NULL;
        temp->next = current;
        temp = temp->next;
    }
}
void nodeInsert(int node, int choice)
{
    /*Add an element to the created list based on the choice given below
        choice = 0,
            Add a node before the first node of the list.
        choice = Any positive number,
            Insert a node in between choice-1 and choice+1 position of the list.
        choice = -1, Add a node at the end of the list.*/

    struct Node *new_node, *temp;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = node;
    if (choice == 0)
    {
        new_node->next = head;
        head = new_node;
    }
    else if (choice == -1)
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
    else
    {
        int p = choice;
        int i = 1;
        int count = 0;
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (p < count)
        {
            temp = head;
            while (i < p - 1)
            {
                temp = temp->next;
                i++;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        else
        {
            cout << "Invalid position";
        }
    }
}
void nodeDelete(int choice)
{
    /*Add an element to the created list based on the choice given below
        choice = 0,
            Delete the first node of the linked list.
        choice = Any positive number,
            Delete the node in between choice-1 and choice+1 position.
        choice = -1, Delete the last node of the list.*/

    struct Node *temp;
    struct Node *prev = NULL;

    if (choice == 0)
    {
        temp = head;
        head = temp->next;
        free(temp);
        temp = NULL;
    }
    if (choice == -1)
    {
        temp = head;
        prev = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        temp = NULL;
    }
    else
    {
        int pos = choice;
        int i = 1;
        temp = head;
        prev = head;
        while (i < pos)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        free(temp);
        temp = NULL;
    }
}
bool nodeSearch(int node)
{
    /*Search the given node in the linked list*/

    struct Node *temp = head;
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == node)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}
void print()
{
    Node *temp = head;
    cout << "\nList is : ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printChoice()
{
    cout << "\n1. Node Insert\n"
         << "2. Node Delete\n"
         << "3. Node Search\n"
         << "4. Print the list\n"
         << "5. Program Exit\n"
         << "Your Choice: ";
}
void printChoice2()
{
    cout << "\nFor first node enter 0\n"
         << "For any node enter the position\n"
         << "For last node enter -1\n"
         << "Your Choice: ";
}
int main()
{
    head = NULL;

    //Initialization of a list
    int arr[] = {1, 5, 8, 7, 9, 2, 4, 3};
    int len = sizeof(arr) / sizeof(arr[0]);

    createList(arr, len);

    while (true)
    {
        printChoice();
        int x, node, choice;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "\nNode value: ";
            cin >> node;

            printChoice2();
            cin >> choice;

            nodeInsert(node, choice);
            break;
        case 2:
            printChoice2();
            cin >> choice;

            nodeDelete(choice);
            break;
        case 3:
            cout << "\nNode value: ";
            cin >> node;

            cout << "\nSearch Result(1/0): " << nodeSearch(node) << endl;
            break;
        case 4:
            print();
            break;
        case 5:
            return 0;
        default:
            cout << "Wrong Choice....\n";
        }
    }
}
