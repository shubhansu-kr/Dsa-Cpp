// Depth first search

#include <iostream>
using namespace std;

struct stack
{
    int *Arr;
    int top;
    int size;
};

void setstack(struct stack *ptr)
{
    // cout << "Enter the size of the stack " << endl ;
    // cin >> ptr->size ;
    ptr->size = 10;
    ptr->top = -1;
    ptr->Arr = (int *)malloc(sizeof(int));
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int a)
{
    ptr->top++;
    ptr->Arr[ptr->top] = a;
}

int pop(struct stack *ptr)
{
    ptr->top--;
    return ptr->Arr[ptr->top + 1];
}

int isPresent(struct stack *ptr, int a)
{
    for (int i = ptr->top; i >= 0; i--)
    {
        if (ptr->Arr[i] == a)
        {
            return 1;
        }
    }
    return 0;
}

// void DFS(int a)
// {
//     cout << a << " ";
//     visited[a] = 1 ;
//     for (int j = 0; j < 7; j++)
//     {
//         if (G[a][j] && visited[j]==0 ) {
//             DFS(j) ;
//         }
//     }
// }

int main()
{
    struct stack *stc = (struct stack *)malloc(sizeof(struct stack));
    setstack(stc);

    // DFS Implementation
    int node;
    int sourceNode = 0; // Starting the DFS from this node
    int G[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    int visited[7] = {0};
    push(stc, sourceNode);
    while (!isEmpty(stc))
    {
        int node = pop(stc);
        for (int i = 0; i < 7; i++)
        {
            if (G[node][i] == 1 && visited[i] == 0)
            {
                push(stc, i);
            }
        }
        if (visited[node] == 0)
        {
            cout << node << " ";
            visited[node] = 1;
        }
    }
    return 0;
}