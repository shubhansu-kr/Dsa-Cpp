// Circular linked list - Deletion

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

// Case 1 : Delete at entry
struct node *Deleteatentry(struct node *ptr)
{
    struct node *p = ptr;
    while (p->next != ptr)
    {
        p = p->next;
    }
    p->next = ptr->next;
    struct node *q = ptr->next;
    free(ptr);
    return q;
}

// case 2 : Delete at end
struct node *Deleteatend(struct node *ptr)
{
    struct node *p = ptr;
    struct node *q;
    while (q->next != ptr)
    {
        p = p->next;
        q = p->next;
    }
    p->next = ptr;
    free(q);
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

    // Deleting element at entry
    n1 = Deleteatentry(n1);
    traversal(n1);

    // Delete element at end
    n1 = Deleteatend(n1);
    traversal(n1);

    return 0;
}