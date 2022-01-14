// Binary tree - linked node 

#include <iostream>
#include <stdlib.h>
using namespace std ;

struct node {
    int data ;
    struct node * left ;
    struct node * right ;
} ;

struct node * createnode (int a) {
    struct node * n = (struct node *) malloc (sizeof(struct node)) ;
    n->data = a ;
    n->left = NULL ;
    n->right = NULL ;
    return n ;
}

int main () {
    struct node * root = createnode(21) ;
    struct node * n1 = createnode(15) ;
    struct node * n2 = createnode(13) ;
    struct node * n3 = createnode(17) ;

    root->right = n2;
    root->left = n1;
    n1->left = n3 ;

    return 0;
}