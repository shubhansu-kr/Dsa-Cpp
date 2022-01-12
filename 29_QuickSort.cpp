// Quicksort

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

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] >= pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);

    swap(A[low], A[j]);

    return j;
}

void quicksort(int A[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(A, low, high);
        quicksort(A, low, partitionindex - 1);
        quicksort(A, partitionindex + 1, high);
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

    quicksort(A, 0, n - 1);
    display(A, n);

    return 0;
}