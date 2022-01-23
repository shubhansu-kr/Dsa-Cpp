// Graphs

#include <iostream>
using namespace std;

struct queue
{
    int rear;
    int front;
    int size;
    int *Arr;
};

void setQueue(struct queue *ptr)
{
    ptr->rear = 0;
    ptr->front = -1;
    ptr->size = 20;
    ptr->Arr = (int *)malloc(ptr->size * sizeof(int));
}

void setdata(struct queue *ptr)
{
    int n;
    cout << "Enter the no. of entries " << endl;
    cin >> n;
    if (n > ptr->size)
    {
        cout << "Not enough space " << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter element " << i + 1 << " : ";
            cin >> ptr->Arr[ptr->rear];
            ptr->rear++;
        }
        ptr->front = 0;
    }
}

int isEmpty(struct queue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    if (ptr->front == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr)
{
    if (ptr->rear == ptr->size)
    {
        return 1;
    }
    return 0;
}

int dequeue(struct queue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Queue is already empty" << endl;
        return -1;
    }
    else
    {
        ptr->front += 1;
        return ptr->Arr[ptr->front - 1];
    }
}

void enqueue(struct queue *ptr, int a)
{
    if (isFull(ptr))
    {
        cout << "Queue is already full" << endl;
    }
    else
    {
        ptr->Arr[ptr->rear] = a;
        ptr->rear++;
    }
}

void traversal(struct queue *ptr)
{
    for (int i = ptr->front; i < ptr->rear; i++)
    {
        cout << ptr->Arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    setQueue(q);
    q->front = 0;
    // setdata(q);
    // traversal(q);

    // BFS Implementation
    int node;
    int sourceNode = 0; // Starting the BFS from this node
    int visited[7] = {0};
    int G[7][7] = {
        {0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 0, 0}};

    cout << sourceNode << " "; // Printing the source node
    visited[sourceNode] = 1;   // Updating the visit tracker since source node is visited

    // Now we need to explore the source node
    // Using an exploration queue

    enqueue(q, sourceNode);
    while (!isEmpty(q))
    {
        int node = dequeue(q);
        for (int i = 0; i < 7; i++)
        {
            if (G[node][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }

    return 0;
}