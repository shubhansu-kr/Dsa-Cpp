// Insertion in linked list

#include <iostream>
using namespace std;

class node
{
    int data;
    int *next;

public:
    node() {}
    node(int a);
    void links(node a);
    void links(void);
    friend void traversal(node a);
    friend void display(node a);
};

node ::node(int a)
{
    data = a;
    next = NULL ;
}

void node ::links(node a)
{
    next = &(a.data);
}
void node ::links(void)
{
    next = NULL;
}

void traversal(node a)
{
    int *ptr = &(a.data);
    while (ptr != NULL)
    {
        cout << " " << *ptr;
        ptr = a.next;
    }
}

void display(node a)
{
    cout <<&(a.data) << " "<<  a.data << " " << a.next << endl;
}

int main()
{
    // node* base = new node (sizeof(node)) ;
    // base -> data = 32 ; data is inaccessible

    node base(43), n1(39), n2(56);
    base.links(n1);
    n1.links(n2);
    n2.links();

    // traversal(base);

    display(base);
    display(n1);
    display(n2);

    return 0;
}