// Doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traversal(struct node *ptr)
{
    struct node *p = ptr;
    while (p->prev != NULL)
    {
        p = p->prev;
    }
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}

void reversetraversal(struct node *ptr)
{
    struct node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->prev;
    }
    printf("\n");
}

int main()
{
    // struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));

    n1->data = 54;
    n2->data = 87;
    n3->data = 76;
    n4->data = 43;

    // Doubly linked list
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    n1->prev = NULL;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;

    traversal(n1);
    // traversal(n2);    -> Gives the same output as n1
    // traversal(n3);    -> Function valid for all nodes
    // traversal(n4);    -> No head node required
    
    reversetraversal(n1);
    // revrsetraversal(n2);    -> Gives the same output as n1
    // revrsetraversal(n3);    -> Function valid for all nodes
    // revrsetraversal(n4);    -> No head node required

    return 0;
}