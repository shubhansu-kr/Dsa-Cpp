// Stack using linked list - push(), pop(), peek()

#include <iostream>
#include <stdlib.h>
using namespace std;

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
    cout << "Enter the size of stack you want " << endl;
    cin >> ptr->size;
    struct node *n;
    n = (struct node *)malloc(ptr->size * sizeof(struct node));
    if (ptr->size == 0)
    {
        n = NULL;
    }
    for (int i = 0; i < ptr->size; i++)
    {
        if (i == ptr->size - 1)
        {
            (n + i)->next = NULL;
        }
        else
        {
            (n + i)->next = (n + 1 + i);
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
        for (int i = 0; i < n; i++)
        {
            printf("Enter element %d \n", i + 1);
            scanf("%d", &((ptr->top) + i)->data);
        }
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full(struct stack *ptr)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traversal(struct stack *ptr)
{
    struct node *p = ptr->top;
    while (p != NULL)
    {
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
}

struct node *push(struct stack *ptr, int a)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = a;
    n->next = ptr->top;
    return n;
}

int pop(struct stack *ptr)
{
    struct node *n = ptr->top;
    ptr->top = n->next;
    int a = n->data;
    free(n);
    return a;
}

int peek(struct stack *ptr, int n)
{
    struct node *p = ptr->top;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    return p->data;
}

int stacktop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        return ptr->top->data;
    }
}

int stackbottom(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        struct node *p = ptr->top;
        while (p->next != NULL)
        {
            p = p->next;
        }
        return p->data;
    }
}

int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->top = NULL;

    setstack(s1);
    setdata(s1);
    traversal(s1);
    s1->top = push(s1, 11);
    traversal(s1);
    cout << pop(s1) << endl;
    traversal(s1);
    cout << peek(s1, 3) << endl;
    cout << stacktop(s1) << endl;
    cout << stackbottom(s1) << endl;

    return 0;
}