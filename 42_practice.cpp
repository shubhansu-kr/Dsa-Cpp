// Practice for bst and avl

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
    n->height = 0;
    n->right = n->left = NULL;
    return n;
}

void inOrderTraversal(struct node *ptr)
{
    if (ptr != NULL)
    {
        inOrderTraversal(ptr->left);
        cout << ptr->data << " ";
        inOrderTraversal(ptr->right);
    }
}

void preOrderTraversal(struct node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        preOrderTraversal(ptr->left);
        preOrderTraversal(ptr->right);
    }
}

void postOrderTraversal(struct node *ptr)
{
    if (ptr != NULL)
    {
        preOrderTraversal(ptr->left);
        preOrderTraversal(ptr->right);
        cout << ptr->data << " ";
    }
}

int isBST(struct node *ptr)
{
    static struct node *prev = NULL;
    if (ptr != NULL)
    {
        if (isBST(ptr->left) == 0)
        {
            return 0;
        }
        if (prev != NULL && ptr->data <= prev->data)
        {
            return 0;
        }
        prev = ptr;
        return isBST(ptr->right);
    }
    return 1;
}

int searchElement(struct node *ptr, int a)
{
    if (ptr != NULL)
    {
        if (ptr->data == a)
        {
            return 1;
        }
        else if (ptr->data < a)
        {
            return searchElement(ptr->right, a);
        }
        else
        {
            return searchElement(ptr->left, a);
        }
    }
    else
    {
        return 0;
    }
}

struct node *insertElement(struct node *ptr, int a)
{
    if (ptr == NULL)
    {
        return createnode(a);
    }
    else
    {
        struct node *p = ptr;
        struct node *q;
        while (p != NULL)
        {
            q = p;
            if (a > p->data)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        p = createnode(a);
        if (q->data > a)
        {
            q->left = p;
        }
        else
        {
            q->right = p;
        }
    }
    return ptr;
}

struct node *inOrderpredecessor(struct node *ptr)
{
    ptr = ptr->left;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr;
}

/*
struct node *  deleteElement(struct node *ptr, int a)
{
    if (ptr == NULL)
    {
        return NULL;
    }
    else if (ptr->left == NULL && ptr->right == NULL)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        if (ptr->data > a)
        {
            return deleteElement(ptr->left, a);
        }
        else if (ptr->data < a)
        {
            return deleteElement(ptr->right, a);
        }
        else
        {
            // ptr->data == a
            struct node *pre = inOrderpredecessor(ptr);
            ptr->data = pre->data;
            ptr->left = deleteElement(ptr->left, ptr->data);
        }
    }
}
*/

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

    inOrderTraversal(root);
    cout << endl;
    // preOrderTraversal(root);
    // cout << endl;
    // postOrderTraversal(root);
    // cout << endl;

    cout << "BST test - " << isBST(root) << endl;
    cout << "Enter the element to search " << endl;
    // int n ;
    // cin >> n;
    // cout << "Element presence : " << searchElement(root, n) << endl;

    // int n;
    // cout << "Enter the element you want to insert " << endl;
    // cin >> n;
    // if (searchElement(root, n))
    // {
    //     cout << "Element already present" << endl;
    // }
    // else
    // {
    //     root = insertElement(root, n);
    // }

    /*
        int n;
        cout << "Enter the element you want to delete " << endl;
        cin >> n;
        if (searchElement(root, n))
        {
            deleteElement(root, n);
        }
        else
        {
            cout << n << " is not present in the bst " << endl;
        } 
    */

    inOrderTraversal(root);
    cout << endl;
    cout << "BST test - " << isBST(root) << endl;

    return 0;
}