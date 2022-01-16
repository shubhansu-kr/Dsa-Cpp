// Searching in Binary tree

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
    else
    {
        return 1;
    }
}

struct node *searchBST(struct node *ptr, int a)
{
    if (ptr != NULL)
    {
        if (ptr->data == a)
        {
            return ptr;
        }
        else if (ptr->data < a)
        {
            return searchBST(ptr->right, a);
        }
        else
        {
            return searchBST(ptr->left, a);
        }
    }
    else
    {
        return NULL;
    }
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

    cout << " BST test - " << isBST(root) << endl;
    int n;
    cout << " Enter the key " << endl;
    cin >> n;
    struct node *key = searchBST(root, n);
    if (key == NULL)
    {
        cout << " Key is not present " << endl;
    }
    else
    {
        cout << " Key is present at " << key << endl;
    }

    return 0;
}