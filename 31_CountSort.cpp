// Count Sort

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

void Countsort(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    cout << "Max element is " << max << endl;

    int Count[max+1] = {0};
    
    /* 
    for (int i = 0; i < max; i++)
    {
        cout << Count[i] << " ";
    }
    cout << endl; 
    */

    for (int i = 0; i < n; i++)
    {   
        int a = A[i] ;
        Count[a]++;
    }

    /* 
    for (int i = 0; i < max; i++)
    {
        cout << Count[i] << " ";
    }
    cout << endl;
    */

    int B[10];
    int j = 0;
    for (int i = 0; i < max+1; i++)
    {
        while (Count[i] != 0)
        {
            B[j] = i;
            j++;
            Count[i]--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
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

    Countsort(A, n);
    display(A, n);

    return 0;
}