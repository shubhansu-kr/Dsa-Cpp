// Paranthesis matching problem

#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
    int top;
    int size;
    char *Arr;
};

void setstack(struct stack *ptr)
{
    ptr->size = 20;
    ptr->top = -1;
    ptr->Arr = (char *)malloc(ptr->size * (sizeof(char)));
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

int push(struct stack *ptr, char a)
{
    if (isFull(ptr) == 1)
    {
        return -1;
    }
    else
    {
        ptr->Arr[ptr->top + 1] = a;
        ptr->top++;
    }
    return 1;
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        return -1;
    }
    else
    {
        ptr->top--;
    }
    return 1;
}

int paramatching(char *p)
{
    struct stack *Exp = (struct stack *)malloc(sizeof(struct stack));
    setstack(Exp);

    int flag = 0;
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (p[i] == '(')
        {
            flag = push(Exp, p[i]);
        }
        else if (p[i] == ')')
        {
            flag = pop(Exp);
        }

        if (flag == -1)
        {
            return -1;
        }
    }
    if (isEmpty(Exp) == 0)
    {
        return -1;
    }
    return 1;
}

int main()
{

    char Expression[20];
    cout << "Enter the expression" << endl;
    cin >> Expression;

    int result = paramatching(Expression);
    if (result == -1)
    {
        cout << "Para dont match " << endl;
    }
    else
    {
        cout << "Para match perfect " << endl;
    }

    return 0;
}