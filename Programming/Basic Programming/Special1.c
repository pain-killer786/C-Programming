//Write a program to add two numbers without using '+' operator.

#include<stdio.h>
int main()
{
    int x,y;
    printf("\n Enter the two numbers to be added:");
    scanf("%d %d", &x, &y);

    while(y!=0)
    {
        x++;
        y--;
    }
    printf("\n Sum of two values is %d", x);
    return 0;
}
