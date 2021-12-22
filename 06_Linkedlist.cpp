// Create linked list using class 

#include <iostream>
using namespace std ;

template <class T>
class node {
    public :
    T data ;
    node * next ;

} ;

int main () {
    node <int> base , second , third ;
    base.data = 43 ;
    second.data = 897 ;
    third.data = 87 ;

    base.next = &second ; 
    second.next = &third ; 
    third.next = NULL ;

    return 0;
}