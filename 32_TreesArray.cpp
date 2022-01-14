// Binary Trees with array

#include <iostream>
using namespace std;

int power(int a, int x)
{
    int pro = 1;
    for (int i = 0; i < x; i++)
    {
        pro *= a;
    }
    return pro;
}

void setarr (int A[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i+1 << " " ;
        cin >> A[i] ;
    }
}

int main()
{
    int n;
    cout << "Enter the depth of tree required " << endl;
    cin >> n;

    int size = power(2, n) - 1;
    int A[size];
    setarr(A, size) ;

    return 0;
}