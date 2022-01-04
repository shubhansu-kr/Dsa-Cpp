// Stacks -> with linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    int size;
    struct node *top;
};

void setstack(struct stack *ptr)
{
    printf("Enter the size of stack \n");
    scanf("%d", &ptr->size);

    struct node *n = (struct node *)calloc(sizeof(struct node), ptr->size);
    for (int i = 0; i < ptr->size; i++)
    {
        if (i == ptr->size - 1)
        {
            (n + i)->next = NULL;
        }
        else
        {
            (n + i)->next = (n + i + 1);
        }
    }
    ptr->top = n;
}

void setdata(struct stack *ptr)
{
    int n;
    printf("Enter the no. of elements you want to add \n");
    scanf("%d", &n);
    if (n > ptr->size)
    {
        printf("The size of stack is only %d \n", ptr->size);
    }
    else
    {
        for (int i = 0; i < n ; i++)
        {
            printf("Enter element %d \n", i + 1);
            scanf("%d", &((ptr->top) + i)->data);
        }
        printf("\n");
    }
}

void traversal(struct stack *ptr)
{
    struct node *p = ptr->top;
    int n = 0;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    for (int i = 0; i < n; i++)
    {
        printf(" %d", ((ptr->top) + i)->data);
    }
    printf("\n");
}

int isEmpty(struct stack *ptr)
{
    struct node *p = ptr->top;
    int n = 0;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    struct node *p = ptr->top;
    int n = 0;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    if (n == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    // s1->size = 5 ;
    // struct node n[5] ;
    setstack(s1);
    setdata(s1);
    traversal(s1);
    printf("Is empty , %d \n", isEmpty(s1));
    printf("Is full , %d \n", isFull(s1));

    return 0;
}