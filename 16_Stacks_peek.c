// Stack peek and traversal

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *Arr;
};

void setstack(struct stack *ptr)
{
    ptr->top = -1;
    printf("Enter the size of stack ");
    scanf("%d", &ptr->size);
    ptr->Arr = (int *)malloc(ptr->size * sizeof(int));
}

void setdata(struct stack *ptr)
{
    int temp;
    printf("How many elements you want to add ");
    scanf("%d", &temp);
    if (temp <= ptr->size)
    {
        for (int i = 0; i < temp; i++)
        {
            printf("Enter element %d : \n", i + 1);
            scanf("%d", &ptr->Arr[i]);
            ptr->top++;
        }
    }
    else
    {
        printf("Size of stack is %d\n", ptr->size);
    }
}

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

void traversal(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stacks is empty \n");
    }
    else
    {
        int n = ptr->top + 1;
        for (int i = n; i > 0; i--)
        {
            printf(" %d", ptr->Arr[i - 1]);
        }
        printf("\n");
    }
}

void peekstack(struct stack *ptr, int n)
{
    if (n > ptr->size)
    {
        printf("Size of stack is %d", ptr->size);
    }
    else
    {
        printf("Element %d is %d \n", n, ptr->Arr[ptr->top + 1 - n]);
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

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is already empty \n");
        return -1;
    }
    else
    {
        int temp = ptr->Arr[ptr->top];
        ptr->top--;
        // printf("Poped out\n");
        return temp;
    }
}
int main()
{
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    setstack(s1);
    // traversal(s1); -> stack is empty
    setdata(s1);
    traversal(s1);
    peekstack(s1, 1);
    peekstack(s1, 2);
    peekstack(s1, 3);

    return 0;
}