// Deletion in linked list

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
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Case 1 : Delete element at start
struct node *Deletebegin(struct node *ptr)
{
    struct node *t = ptr;
    ptr = ptr->next;
    t->next = NULL;
    free(t);
    return ptr;
}

// Case 2 : Delete element at end ;
struct node *Deleteend(struct node *ptr)
{
    struct node *t = ptr;
    while ((ptr->next)->next != NULL)
    {
        ptr = ptr->next;
    }
    struct node * q = ptr->next ;
    ptr->next = NULL;
    free (q) ;
    return t;
}

// Case 3 : Delete specific value ;
struct node *Deleteval(struct node *ptr, int a)
{
    struct node *p = ptr;
    struct node *t = ptr;
    for (int i = 0; i < 4; i++)
    {
        if (p->data == a)
        {
            break;
        }
        p = p->next;
    }
    while (ptr != NULL)
    {
        if (ptr->next == p)
        {
            break;
        }
        ptr = ptr->next;
    }
    ptr->next = p->next;
    free(p);
    return t;
}

// Case 4 : Delete with specific pointer
struct node *Deleteptr(struct node *ptr, struct node *a)
{
    struct node *t = ptr;

    while (ptr != NULL)
    {
        if (ptr->next == a)
        {
            break;
        }
        ptr = ptr->next;
    }
    ptr->next = a->next;
    free (a) ;
    return t;
}

// Case 4 : Delete at index
struct node *Deleteindex(struct node *ptr, int a)
{
    struct node *p = ptr;
    for (int i = 0; i < a - 1; i++)
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return ptr;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *n1 = (struct node *)malloc(sizeof(struct node));
    struct node *n2 = (struct node *)malloc(sizeof(struct node));
    struct node *n3 = (struct node *)malloc(sizeof(struct node));

    head->data = 23;
    n1->data = 43;
    n2->data = 78;
    n3->data = 65;

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    traversal(head);

    // head = Deletebegin(head);
    // traversal(head);

    // head = Deleteend(head);
    // traversal(head);
    // free(n3);

    // head = Deleteval(head, 78);
    // traversal(head);

    // head = Deleteptr(head, n2);
    // traversal(head);

    head = Deleteindex(head, 2);
    traversal(head);

    return 0;
}