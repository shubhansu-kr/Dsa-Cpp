// Queue using array

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct Queue
{
    struct node *rear;
    struct node *front = NULL;
};

void setqueue(struct Queue *ptr)
{
    int n;
    cout << "Enter the number of data entries " << endl;
    cin >> n;

    ptr->front = (struct node *)malloc(n * sizeof(struct node));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << "Enter element " << i + 1 << endl;
            cin >> (ptr->front)->data;
            ptr->rear = ptr->front;
            ptr->rear->next = ptr->rear + 1;
        }
        else if (i == n - 1)
        {
            ptr->rear = ptr->rear + 1;
            cout << "Enter element " << i + 1 << endl;
            cin >> (ptr->rear)->data;
            ptr->rear->next = NULL;
        }
        else
        {
            ptr->rear = ptr->rear + 1;
            cout << "Enter element " << i + 1 << endl;
            cin >> (ptr->rear)->data;
            ptr->rear->next = ptr->rear + 1;
        }
    }
}

void traversal(struct Queue *ptr)
{
    struct node *p = ptr->front;
    while (p != NULL)
    {
        cout << " " << p->data;
        p = p->next;
    }
    cout << endl;
}

void peek(struct Queue *ptr, int n)
{
    struct node *p = ptr->front;
    for (int i = 1; i < n; i++)
    {
        p = p->next;
    }
    cout << " Element at index " << n << " is " << p->data << endl;
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->front == NULL)
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
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dequeue(struct Queue *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        struct node *p = ptr->front;
        ptr->front = ptr->front->next;
        free(p);
    }
}

void enqueue(struct Queue *ptr, int a)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = a;
    p->next = NULL;
    ptr->rear->next = p;
    ptr->rear = p;
}

int main()
{
    struct Queue *N1 = (struct Queue *)malloc(sizeof(struct Queue));
    setqueue(N1);
    traversal(N1);
    dequeue(N1);
    traversal(N1);
    enqueue(N1, 90);
    traversal(N1);
    peek(N1, 2);

    return 0;
}