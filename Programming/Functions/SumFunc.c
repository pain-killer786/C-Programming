#include<stdio.h>

int Sum(int a, int b);

int main()
{
    int a,b;
    printf("Enter the values of a and b");
    scanf("%d %d", &a, &b);   
    printf("The sum of teo number is %d",Sum(a,b));
    return 0;
}

int Sum(int x, int y)
{
    int s=0;
    s=x+y;
    return s;    
}