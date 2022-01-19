// AVL - Practice

#include <iostream>
using namespace std;

class node
{
    int data;
    class node *left;
    class node *right;
    int height;

public:
    node *createnode(int a);
    int getHeight();
    int getBalancefactor();
    void display();
    node *leftrotate();
};

int node ::getHeight()
{
    return height;
}

int node ::getBalancefactor()
{
    return left->height - right->height;
}
node *node ::leftrotate()
{
    node *p = right;
    node *q = p->left;

    return NULL;
}

void node ::display()
{
    cout << " " << data << endl;
}

node *node ::createnode(int a)
{
    node *n = new (node);
    n->data = a;
    n->right = n->left = NULL;
    n->height = 0;
    return n;
}
/*
int node ::getHeight()
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return height;
    }
}

int node :: getBalancefactor (class node * ptr) {
    if (ptr == NULL ) {
        return 0 ;
    }
    else {
        return ptr->left->getHeight() - ptr->right->getHeight() ;
    }
}
*/

int main()
{
    node *root = root->createnode(4);
    root->display();

    return 0;
}