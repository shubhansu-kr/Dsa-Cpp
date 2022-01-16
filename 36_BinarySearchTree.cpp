// Binary search tree

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int a)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inOrder(ptr->left);
        cout << ptr->data << " ";
        inOrder(ptr->right);
    }
    // cout << endl; -> recursive call 
}

int main()
{
    struct node *root = createnode(9);
    struct node *n1 = createnode(4);
    struct node *n2 = createnode(11);
    struct node *n3 = createnode(2);
    struct node *n4 = createnode(7);
    struct node *n5 = createnode(5);
    struct node *n6 = createnode(8);
    struct node *n7 = createnode(19);
    struct node *n8 = createnode(14);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n4->left = n5;
    n4->right = n6;

    n2->right = n7;
    n7->left = n8;

    inOrder(root); // Inorder traversal of BST gives ascending data 

    return 0;
}