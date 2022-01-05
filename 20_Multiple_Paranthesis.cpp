// Multiple Paranthesis code

#include <iostream>
#include <stdlib.h>
using namespace std;

struct stack
{
    int size;
    int top;
    char *Arr;
};

void setstack(struct stack *ptr)
{
    ptr->top = -1;
    ptr->size = 20;
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

int pop(struct stack *ptr, char a)
{
    if (isEmpty(ptr) == 1)
    {
        return -1;
    }
    else
    {
        char temp = ptr->Arr[ptr->top];
        char match;
        if (temp == '(')
        {
            match = ')';
        }
        else if (temp == '{')
        {
            match = '}';
        }
        else
        {
            match = ']';
        }
        ptr->top--;
        if (a == match)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int push(struct stack *ptr, char a)
{
    if (isFull(ptr) == 1)
    {
        return -1;
    }
    ptr->top++;
    ptr->Arr[ptr->top] = a;
    return 1;
}

int Paranthesis(struct stack *ptr, char *A, int n)
{
    int flag;
    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == '(' || A[i] == '{' || A[i] == '[')
        {
            flag = push(ptr, A[i]);
        }
        else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
        {
            flag = pop(ptr, A[i]);
        }
        if (flag == -1)
        {
            return -1;
        }
    }
    if (isEmpty(ptr) == 0)
    {
        return -1;
    }
    return 1;
}

int main()
{
    int n;
    cout << "Enter the size of expression " << endl;
    cin >> n;
    char Expression[n];
    cout << "Enter the Expression " << endl;
    cin >> Expression;

    struct stack *Exp = (struct stack *)malloc(sizeof(struct stack));
    setstack(Exp);

    int result = Paranthesis(Exp, Expression, n);
    if (result == -1)
    {
        cout << "Paranthesis don't match" << endl;
    }
    else
    {
        cout << "Paranthesis match perfect" << endl;
    }

    return 0;
}