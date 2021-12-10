// Array Adt using class

#include <iostream>
using namespace std;

class Myarray
{
    int tsize;
    int usize;
    int *p;

public:
    Myarray();
    Myarray(int a, int b)
    {
        tsize = a;
        usize = b;
        p = new int(a * sizeof(int));
    }
    void setdata();
    void getdata();

};

void Myarray ::setdata()
{
    for (int i = 0; i < usize; i++)
    {
        cout << "Enter element " << i + 1 << " " << endl;
        scanf("%d", p + i);
    }
}

void Myarray ::getdata()
{
    for (int i = 0; i < usize; i++)
    {
        cout << *(p + i) << " ";
    }
}

int main()
{
    Myarray A(10, 3);
    A.setdata();
    A.getdata();

    return 0;
}