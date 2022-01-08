// Circular Queue using Arrays

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct Queue
{
    int size;
    int *Arr;
    int front;
    int rear;
};

void setQueue(struct Queue *ptr)
{
    ptr->front = ptr->rear = -1;
    ptr->size = 10;
    ptr->Arr = (int *)malloc(ptr->size * sizeof(int));
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue *ptr)
{
    if (abs(ptr->rear - ptr->front) == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void setdata(struct Queue *ptr)
{
    cout << "Enter the no. of items to queue " << endl;
    int n;
    cin >> n;

    if (n > ptr->size - abs(ptr->rear - ptr->front))
    {
        cout << "Too many items to queue" << endl;
    }
    else
    {
        if (n > 0)
        {
            if (ptr->front == -1)
            {
                ptr->front = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            ptr->rear = (ptr->rear + 1) % ptr->size;
            cout << "Enter element " << i + 1 << endl;
            cin >> ptr->Arr[ptr->rear];
        }
    }
}
void enqueue(struct Queue *ptr, int a)
{
    if (isFull(ptr))
    {
        cout << "Queue is full, wait outside " << endl;
    }
    else
    {
        ptr->rear = (ptr->rear + 1) % ptr->size;
        ptr->Arr[ptr->rear] = a;
    }
    cout << endl;
}

void dequeue(struct Queue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        ptr->front = (ptr->front + 1) % ptr->size;
    }
}

void traversal(struct Queue *ptr)
{

    for (int i = ptr->front; i != ptr->rear; i = (i + 1) % ptr->size)
    {
        cout << " " << ptr->Arr[i];
    }
    cout << " " << ptr->Arr[ptr->rear] << endl;
}

int count(struct Queue *ptr)
{
    if (ptr->rear > ptr->front)
    {
        return abs(ptr->rear - ptr->front);
    }
    else {
        return (ptr->size - ptr->front) + (ptr->rear +1 ) ;
    }
}

void peek(struct Queue *ptr, int n)
{
    if (n > count(ptr))
    {
        cout << "Invalid index " << endl;
    }
    else
    {
        if (ptr->size - ptr->front >= n)
        {
            cout << "Item at index " << n << " is " << ptr->Arr[ptr->front + n - 1] << endl;
        }
        else
        {
            int x = n - (ptr->size - ptr->front) - 1;
            cout << "Item at index " << n << " is " << ptr->Arr[x] << endl;
        }
    }
}

int main()
{
    struct Queue *N1 = (struct Queue *)malloc(sizeof(struct Queue));
    setQueue(N1);
    setdata(N1);
    traversal(N1);
    for (int i = 0; i < 3; i++)
    {
        dequeue(N1);
        enqueue(N1, i + 3);
        traversal(N1);
    }

    peek(N1, 8);
    return 0;
}