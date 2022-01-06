// Infix to postfix
// For simple operator only

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct stack
{
    int size;
    int top;
    char *Arr;
};

void setstack(struct stack *ptr)
{
    ptr->size = 20;
    ptr->top = -1;
    ptr->Arr = (char *)malloc(ptr->size * sizeof(char));
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

void push(struct stack *ptr, char a)
{
    ptr->top++;
    ptr->Arr[ptr->top] = a;
}

char pop(struct stack *ptr)
{
    char temp = ptr->Arr[ptr->top];
    ptr->top--;
    return temp;
}

int precedence(char a)
{
    if (a == '-' || a == '+')
    {
        return 1;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void control(struct stack *ptr, char a, char *p, int &n)
{
    if (isEmpty(ptr) == 1)
    {
        push(ptr, a);
    }
    else
    {
        // x-y/z-k*d -> xyz/kd*--☺O≈↔☻
        int x = ptr->top + 1;
        for (int i = 0; i < x; i++)
        {
            if (precedence(a) == precedence(ptr->Arr[ptr->top]))
            {
                p[n] = pop(ptr);
                n++;
            }
            else if (precedence(a) < precedence(ptr->Arr[ptr->top]))
            {
                p[n] = pop(ptr);
                n++;
            }
        }
        push(ptr, a);
    }
}

char *Infixtopostfix(char *a)
{
    char *postfix = (char *)malloc(strlen(a) + 1);
    struct stack *E = (struct stack *)malloc(sizeof(struct stack));
    setstack(E);
    int j = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '*' || a[i] == '/' || a[i] == '+' || a[i] == '-')
        {
            control(E, a[i], postfix, j);
        }
        else
        {
            postfix[j] = a[i];
            j++;
        }
    }
    int x = E->top + 1;
    for (int i = 0; i < x; i++)
    {
        if (isEmpty(E) != 1)
        {
            postfix[j] = pop(E);
            j++;
        }
    }
    postfix[j] = '\0';
    
    return postfix;
}

int main()
{
    char Exp[20];
    cout << "Enter the expression " << endl;
    cin >> Exp;

    char *Postfixexp = Infixtopostfix(Exp);

    for (int i = 0; i < strlen(Exp); i++)
    {
        printf("%c", Postfixexp[i]);
    }
    cout << endl;

    return 0;
}