// Pre0rder

#include <iostream>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *createnode(int a)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

int main()
{
    struct node *root = createnode(4);
    struct node *n1 = createnode(1);
    struct node *n2 = createnode(6);
    struct node *n3 = createnode(3);
    struct node *n4 = createnode(5);
    struct node *n5 = createnode(2);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->right = n5;

    preorder(root);
    return 0;
}