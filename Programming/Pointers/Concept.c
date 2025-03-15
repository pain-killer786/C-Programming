//Pointer are derived Datatypes
#include<stdio.h>
int main()
{
    //Syntax:- datatype *pointer;
    int a=10;
    float b=10.3;
    int *p; //*is dereferencing operator
    p=&a; // Here & is the address operator
    printf("%d\n", *p); //10
    printf("%x", &a);   //Hexadecimal Output


    /*Double Pointer*/
    int **q=&p;
    printf("%d %d %d", a, *p,**q);

}