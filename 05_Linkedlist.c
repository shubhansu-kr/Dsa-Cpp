// Creating linked list using structure

#include <stdio.h>
#include <stdlib.h>

// node is the user defined data type we will use to make nodes

struct node
{
    int data;          // The data stored in each node
    struct node *next; // pointer for next node ;
};

void Traversal(struct node *ptr)
{
    while (ptr != NULL) {
        printf ("Element : %d \n", ptr->data) ;
        ptr = ptr->next ;
    }
}

int main()
{

    // Dynamic allocation for nodes
    struct node *Base;
    struct node *Second;
    struct node *Third;
    struct node *Fourth; // created four nodes for list

    Base = (struct node *)malloc(sizeof(struct node));
    Second = (struct node *)malloc(sizeof(struct node));
    Third = (struct node *)malloc(sizeof(struct node));
    Fourth = (struct node *)malloc(sizeof(struct node));

    // setting data of nodes and linking nodes
    Base->data = 43;
    Base->next = Second;

    Second->data = 675;
    Second->next = Third;

    Third->data = 423;
    Third->next = Fourth;

    Fourth->data = 870;
    Fourth->next = NULL;

    Traversal (Base) ;

    return 0;
}