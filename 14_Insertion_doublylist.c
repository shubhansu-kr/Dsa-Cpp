// Insertion doubly-linked list

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

void Insertatbeginning(struct node *ptr, int a)
{
    struct node *p = ptr;
    while (p->prev != NULL)
    {
        p = p->prev;
    }
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->prev = NULL;
    n->next = p;
    p->prev = n;
}

void Insertatend(struct node *ptr, int a)
{
    struct node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->next = NULL;
    p->next = n;
    n->prev = p;
}

void Insertatintdex(struct node *ptr, int a, int b)
{
    struct node *p = ptr;
    while (p->prev != NULL)
    {
        p = p->prev;
    }
    for (int i = 0; i < a - 1; i++)
    {
        p = p->next;
    }
    struct node *q = p->next;
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = b;
    n->next = q;
    n->prev = p;
    p->next = n;
    q->prev = n;
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

    Insertatbeginning(n2, 66);
    traversal(n1);

    Insertatend(n2, 99);
    traversal(n1);

    Insertatintdex(n1, 3, 11);
    traversal(n1);

    return 0;
}