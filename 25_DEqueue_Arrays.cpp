// DE queue - Double ended Queue using arrays

#include <iostream>
#include <stdlib.h>
using namespace std;

struct queue
{
    int front;
    int size;
    int rear;
    int *Arr;
};

void setqueue(struct queue *ptr)
{
    ptr->front = ptr->rear = -1;
    ptr->size = 10;
    ptr->Arr = (int *)malloc(ptr->size * sizeof(int));
}

void setdata(struct queue *ptr)
{
    int n;
    cout << "Enter the no. of entries " << endl;
    cin >> n;

    if (n > ptr->size)
    {
        cout << "Too many items " << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Element " << i + 1 << endl;
            cin >> ptr->Arr[i];
            ptr->rear++;
        }
        ptr->front = 0;
    }
}

int isEmpty(struct queue *ptr)
{
    if (ptr->front == ptr->rear + 1 )
    {
        return 1;
    }
    else if (ptr->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *ptr)
{
    if (ptr->rear - ptr->front == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traversal(struct queue *ptr)
{
    for (int i = ptr->front; i <= ptr->rear; i++)
    {
        cout << " " << ptr->Arr[i];
    }
    cout << endl;
}

void enqueueF(struct queue *ptr, int n)
{
    if (ptr->front == 0)
    {
        cout << "Queue is full at front" << endl;
    }
    else
    {
        ptr->front--;
        ptr->Arr[ptr->front] = n;
    }
}

void dequeueF(struct queue *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        cout << "Queue is empty " << endl;
    }
    else
    {
        ptr->front++;
    }
}

void enqueueR (struct queue *ptr, int n ) {
    if (ptr->rear == ptr->size-1) {
        cout << "Queue is full " << endl;
    }    
    else {
        ptr->rear ++ ;
        ptr->Arr[ptr->rear] = n ;
    }
}

void dequeueR (struct queue * ptr ) {
    if (isEmpty(ptr)) {
        cout << "Queue is empty " << endl; 
    }
    else {
        ptr->rear -- ;
    }
}

int main()
{
    struct queue N1;
    setqueue(&N1);
    setdata(&N1);
    traversal(&N1);

    return 0;
}