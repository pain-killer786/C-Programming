//Write a program to add two numbers without using '+' operator (Half Adder Method).

#include<stdio.h>
int main()
{
    int x,y;
    printf("\n Enter the two numbers to be added:");
    scanf("%d %d", &x, &y);
    if(y>0)
    {
        while(y!=0)
        {
            x++;
            y--;
        }
    }
    else if(y<0)
    {
        while(y!=0)
        {
            x--;
            y++;
        }
    }
    printf("\n Sum of two values is %d", x);
    return 0;
}
