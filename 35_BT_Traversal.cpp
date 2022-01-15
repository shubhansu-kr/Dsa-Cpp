// Post order traversal in BT

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

void postOrder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " ";
    }
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

void inorder (struct node * ptr) {
    if (ptr != NULL) {
        inorder (ptr->left) ;
        cout << ptr->data << " " ;
        inorder (ptr->right) ;
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

    cout << " Pre order - ";
    preorder(root);
    cout << endl;
    cout << " Post order - ";
    postOrder(root);
    cout << endl;
    cout << " In order - " ;
    inorder(root) ;

    return 0;
}