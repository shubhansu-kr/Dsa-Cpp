// insertion at an index in array

#include <iostream>
using namespace std;

// code for traversal
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}

// code for insertion 
int insert(int a[], int &n, int b)
{
    if (n >= 10)
    {
        return -1;
    }
    else
    {
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b && b < a[i + 1])
            {
                ind = i;
                break;
            }
        }
        for (int i = n; i > ind; i--)
        {
            a[i + 1] = a[i];
        }
        a[ind + 1] = b;
        n++;
        return 1;
    }
}

int main()
{

    int A[10] = {3, 5, 34, 43, 46};
    int size = 5, element;
    cout << "Enter the element you want to insert" << endl;
    cin >> element;

    display(A, size);
    insert(A, size, element);
    display(A, size);

    return 0;
}