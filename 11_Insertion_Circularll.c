// Circular linked list - Insertion

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    struct node *p = ptr;
    while (p->next != ptr)
    {
        printf(" %d", p->data);
        p = p->next;
    }
    printf(" %d\n", p->data);
}

struct node *Insertatentry(struct node *ptr, int a)
{
    struct node *p = ptr;
    struct node *x = (struct node *)malloc(sizeof(struct node));
    while (p->next != ptr)
    {
        p = p->next;
    }
    x->data = a;
    p->next = x;
    x->next = ptr;

    return x;
}

struct node *Insertatend(struct node *ptr, int a)
{
    struct node *p = ptr;
    struct node *x = (struct node *)malloc(sizeof(struct node));
    while (p->next != ptr)
    {
        p = p->next;
    }
    x->data = a;
    p->next = x;
    x->next = ptr;

    return ptr;
}

struct node *Insertatindex(struct node *ptr, int n, int a)
{
    struct node *p = ptr;
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->data = a;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = x;
    x->next = q;
    return ptr;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));
    struct node *n4 = (struct node *)malloc(sizeof(struct node));

    n1->data = 54;
    n2->data = 87;
    n3->data = 76;
    n4->data = 43;

    // head will be used as a entry point in circular list

    // circular link
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;

    traversal(n1);

    n1 = Insertatentry(n1, 99);
    traversal(n1);

    n1 = Insertatindex(n1, 2, 44);
    traversal(n1);

    n1 = Insertatend(n1, 66);
    traversal(n1);

    return 0;
}