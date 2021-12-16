// deletion of element in array

#include <iostream>
using namespace std;

void elementdel(int a[], int &n, int b)
{
    int ind;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b)
        {
            ind = i;
        }
    }
    for (int i = ind; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = 0;
    n--;
}

void indexdel(int a[], int &n, int b)
{
    for (int i = b; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    a[n - 1] = 0;
    n--;
}

void setdata(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " ";
        cin >> a[i];
    }
    cout << endl; 
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl; 
}

int main()
{
    int A[10];

    int size;
    cout << "Enter the no of elements" << endl;
    cin >> size;

    setdata(A, size);
    display(A, size);

    int element;
    cout << "Enter the element you want to delete " << endl;
    cin >> element;

    elementdel(A, size, element);
    display(A, size);

    int index;
    cout << "Enter the index value " << endl;
    cin >> index;

    indexdel(A, size, index);
    display(A, size);

    return 0;
}