// Merge sort

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
/*

int *merge(int A[], int m, int B[], int n)
{
    int *C = (int *)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k] = A[i];
            k++;
            i++;
        }
        else
        {
            C[k] = B[j];
            k++;
            j++;
        }
    }
    while (i < m)
    {
        C[k] = A[i];
        k++;
        i++;
    }
    while (j < n)
    {
        C[k] = B[j];
        k++;
        j++;
    }
    return C;
}
*/

void merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[10];
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    /* int m;
    cout << "Enter the size of array A " << endl;
    cin >> m;

    int A[m];
    setarr(A, m);
    display(A, m); */

    // int n;
    // cout << "Enter the size of array B" << endl;
    // cin >> n;

    // int B[n];
    // setarr(B, n);
    // display(B, n);

    /* int *C = merge(A, m, B, n);
    display(C, n + m); */

    /* int C[m + n];
    mergesort(A, m, B, n, C);
    cout << "Merged A and B" << endl;
    display(C, m + n); */

    int A[] = {2, 23, 43, 3, 33, 65};
    display(A, 6);
    mergesort(A, 0, 5);
    display(A, 6);

    return 0;
}