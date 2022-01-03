// Stacks using array

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *Arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
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
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int a)
{
    if (isFull(ptr))
    {
        printf("Stack is full, Can't push \n");
    }
    else
    {
        ptr->Arr[ptr->top + 1] = a;
        ptr->top++;
        printf("Pushed %d\n", a);
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is already empty \n");
    }
    else
    {
        ptr->top--;
        printf("Poped out\n");
    }
}

void display(struct stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf(" %d", ptr->Arr[i]);
    }
    printf ("\n") ;
}

int main()
{
    // struct stack S;
    // S.size = 10;
    // S.top = -1;
    // printf("%d\n", S.size);
    // printf("%d\n", S.top);
    // printf("%u\n", S.Arr);
    // printf("%d\n", sizeof(struct stack));

    struct stack *S = (struct stack *)malloc(sizeof(struct stack));
    S->size = 5;
    S->top = -1;
    S->Arr = (int *)malloc(S->size * sizeof(int));

    // printf("Stack empty status %d \n", isEmpty(S));

    // *(S->Arr) = 3; -> one way to do it
    S->Arr[0] = 3; // easy way out
    S->top++;

    // printf("Stack empty status %d \n", isEmpty(S));

    display(S);

    push(S, 43);
    push(S, 65);
    push(S, 23);
    push(S, 14);

    display(S);

    pop(S) ;
    display(S);

    return 0;
}