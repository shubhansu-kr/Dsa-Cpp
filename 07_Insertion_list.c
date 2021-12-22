// Insertion in a linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *begining_insert(struct node *base, int a)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = a;
    ptr->next = base;
    return ptr;
    // traversal(base);
}

struct node *index_insert(struct node *base, int index, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = base;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return base;
}

struct node *end_insert(struct node *base,int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = base;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return base;
}

struct node * node_insert (struct node *p, struct node * base , int data) {
    struct node * ptr = (struct node*) malloc (sizeof (struct node)) ;
    ptr->data = data ;
    ptr->next = p->next ;
    p->next = ptr ;
    return base ;    
}

int main()
{
    struct node *base;
    struct node *n1;
    struct node *n2;
    struct node *n3;

    base = (struct node *)malloc(sizeof(struct node));
    n1 = (struct node *)malloc(sizeof(struct node));
    n2 = (struct node *)malloc(sizeof(struct node));
    n3 = (struct node *)malloc(sizeof(struct node));

    base->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    base->data = 43;
    n1->data = 76;
    n2->data = 56;
    n3->data = 67;

    traversal(base);
    printf("\n");
    // traversal(n2);

    // struct node *n0 = (struct node *)malloc(sizeof(struct node));
    // n0->data = 90;

    base = begining_insert(base, 56);
    traversal(base);
    printf("\n");

    base = end_insert(base, 36);
    traversal(base);
    printf("\n");

    base = node_insert(n2,base,36);
    traversal(base);
    printf("\n");

    base = index_insert(base, 2, 21);
    traversal(base);

    return 0;
}