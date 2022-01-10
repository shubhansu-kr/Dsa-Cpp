// Bubble sort algo

#include <iostream>

using namespace std;

void traversal(int A[], int n)
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

void bubblesort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
            }
        }
    }
}

void bubblesortadaptive(int A[], int n)
{
    int issorted = 0 ;

    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1 ;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j+1], A[j]);
                issorted = 0 ;
            }
        }
        if (issorted) {
            break ;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << endl;
        cin >> A[i];
    }

    cout << "Orignal array - ";
    traversal(A, n);

    bubblesort(A, n);

    cout << "Sorted Array - ";
    traversal(A, n);

    return 0;
}