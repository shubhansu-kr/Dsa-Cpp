// Circular linked list

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
    while (p->next != ptr) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf(" %d\n", p->data);
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
    
    return 0;
}