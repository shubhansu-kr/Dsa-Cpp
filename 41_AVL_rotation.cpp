// AVL trees - Balanced binary tree
// |BF| <= 1 ;
// AVL trees - Rotation

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
    int height;
};

int getHeight(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return ptr->height;
    }
}

struct node *createnode(int a)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

int getBalancefactor(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(ptr->left) - getHeight(ptr->right);
    }
}

struct node *leftRotate(struct node *ptr)
{
    struct node *p = ptr->right;
    struct node *q = p->left;

    p->left = ptr;
    ptr->right = q;

    ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

    return p;
}

struct node *rightRotate(struct node *ptr)
{
    struct node *p = ptr->left;
    struct node *q = p->right;

    p->right = ptr;
    ptr->left = q;

    ptr->height = max(getHeight(ptr->left), getHeight(ptr->right)) + 1;
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

    return p;
}

struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        return createnode(key);
    }
    if (key < ptr->data)
    {
        ptr->left = insert(ptr->left, key);
    }
    else if (key > ptr->data)
    {
        ptr->right = insert(ptr->right, key);
    }
    ptr->height = 1 + max(getHeight(ptr->left), getHeight(ptr->right));
    int bf = getBalancefactor(ptr);

    // left left case
    if (bf > 1 && ptr->left->data > key)
    {
        return rightRotate(ptr);
    }
    // right right case
    if (bf < -1 && ptr->left->data < key)
    {
        return leftRotate(ptr);
    }
    // left right case
    if (bf > 1 && ptr->left->data < key)
    {
        ptr->left = leftRotate(ptr->left) ;
        return rightRotate(ptr);
    }
    // right left case
    if (bf < -1 && ptr->left->data > key)
    {
        ptr->left = rightRotate(ptr->right) ;
        return rightRotate(ptr);
    }
    return ptr ;
}

int main()
{
    struct node * root = NULL ;
    root = insert (root , 1 ) ;
    root = insert (root , 3 ) ;
    root = insert (root , 4 ) ;
    root = insert (root , 7 ) ;
    root = insert (root , 34 ) ;
    root = insert (root , 2 ) ;
    root = insert (root , 54 ) ;
    root = insert (root , 23 ) ;
    return 0;
}