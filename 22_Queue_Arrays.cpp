// Que Adt using Arrays and

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue
{
    int size;
    int front;
    int rear;
    int *Arr;
};

void setQueue(struct Queue *ptr)
{
    ptr->size = 20;
    ptr->front = -1;
    ptr->rear = -1;
    ptr->Arr = (int *)malloc(ptr->size * sizeof(int));
}

int Queuestat(struct Queue *ptr)
{
    return ptr->rear + 1;
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->rear == ptr->front)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *ptr, int a)
{
    if (isFull(ptr))
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        ptr->rear++;
        ptr->Arr[ptr->rear] = a;
    }
}

void dequeue(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        ptr->front++;
    }
}

void setdata(struct Queue *ptr)
{
    int n;
    cout << "Enter the no of enteries " << endl;
    cin >> n;

    if (n > ptr->size)
    {
        cout << "Size is only " << ptr->size << endl;
    }
    else
    {
        ptr->front = 0;
        for (int i = 0; i < n; i++)
        {
            ptr->rear++;
            cout << "Enter element " << i + 1 << endl;
            cin >> ptr->Arr[ptr->rear];
        }
    }
    cout << endl;
}

void traversal(struct Queue *ptr)
{
    for (int i = ptr->front; i <= ptr->rear; i++)
    {
        cout << " " << ptr->Arr[i];
    }
    cout << endl;
}

void peek(struct Queue *ptr, int n)
{
    cout << "Element at " << n << " is " << ptr->Arr[ptr->front + n - 1] << endl;
}

int main()
{
    struct Queue *Icecream = (struct Queue *)malloc(sizeof(struct Queue));
    setQueue(Icecream);

    setdata(Icecream);
    traversal(Icecream);
    cout << "dequeue " << endl;
    dequeue(Icecream);
    traversal(Icecream);
    cout << "enqueue" << endl;
    enqueue(Icecream, 99);
    traversal(Icecream);

    return 0;
}