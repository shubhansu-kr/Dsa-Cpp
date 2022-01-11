// Insertion sort

#include <iostream>
using namespace std;

void setarr(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << endl;
        cin >> A[i];
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Insertionsort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        int count = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (x < A[j])
            {
                A[j + 1] = A[j];
                count++;
            }
            else
            {
                break;
            }
        }
        A[i - count] = x;
    }
}

void AdaptiveInsertionsort(int A[], int n)
{
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < A[i + 1])
        {
            start++;
        }
        else
        {
            break;
        }
    }

    for (int i = start + 1; i < n; i++)
    {
        int x = A[i];
        int count = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (x < A[j])
            {
                A[j + 1] = A[j];
                count++;
            }
            else
            {
                break;
            }
        }
        A[i - count] = x;
    }
}

int main()
{
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;

    int A[n];
    setarr(A, n);
    display(A, n);

    // Insertionsort(A, n);
    AdaptiveInsertionsort(A, n);
    display(A, n);

    return 0;
}