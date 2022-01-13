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

void merge(int A[], int B[], int m, int n)
{
    
}

int main()
{

    int n;
    cout << "Enter the size of array " << endl;
    cin >> n;

    int A[n];
    setarr(A, n);
    display(A, n);

    return 0;
}