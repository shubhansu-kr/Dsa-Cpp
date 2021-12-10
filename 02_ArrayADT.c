// Array - User defined

#include <stdio.h>
#include <stdlib.h>

struct Myarray
{
    int tsize;
    int usize;
    int *p;
};

void create(struct Myarray *a, int b, int c)
{
    (*a).tsize = b;
    // (*a).usize = c ;
    a->usize = c;
    a->p = (int *)malloc(b * sizeof(int));
}

void setdata(struct Myarray *a)
{
    for (int i = 0; i < a->usize; i++)
    {
        printf("\n Enter element %d ", i + 1);
        scanf("%d", (a->p + i));
    }
}

void display(struct Myarray a)
{
    for (int i = 0; i < a.usize; i++)
    {
        printf("\n %d ", *(a.p + i));
    }
}

void insert(struct Myarray *a, int b, int c)
{
    // b -> index value where you want to change the address
    // c -> the value to be inserted
    // rest element would have to shift and used size would be updated
    int i = a->usize;
    int j = *(a->p + b);
    *(a->p + i) = j;
    *(a->p + b) = c;
    a->usize ++ ;
}

int main()
{
    struct Myarray A;
    create(&A, 10, 5);
    setdata(&A);
    display(A);
    insert(&A, 3, 21);
    printf("\n");
    display(A);

    return 0;
}