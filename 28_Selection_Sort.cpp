// Selection Sort

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

void Selectionsort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int x = i;
        int min = A[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > A[j])
            {
                min = A[j];
                x = j;
            }
        }
        swap(A[i], A[x]);
    }
}

/* void AdaptiveSelectionsort(int A[], int n)
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

    for (int i = start; i < n - 1; i++)
    {
        int x = 0;
        int min = A[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > A[j])
            {
                min = A[j];
                x = j;
            }
        }
        swap(A[i], A[x]);
    }
}
*/

// selection sort cant be improvised as adaptive

int main()
{
    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;

    int A[n];
    setarr(A, n);
    display(A, n);

    Selectionsort(A, n);
    display(A, n);

    return 0;
}