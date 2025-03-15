// Write a program to check whether a number is strong number or not.

#include<stdio.h>

int main()
{
    int n,q,d,i,fact=1,sum=0;
    printf("\n Enter a number:-");
    scanf("%d", &n);
    q=n;
    
    while(q!=0)
    {
        d=q%10;
        for(i=d;i>1;i--)
        {
            fact=fact*i;
        }
        sum=sum+fact;
        fact=1;
        q=q/10;
    }
    if(d<0)
    {
        exit(1);
    }
    
    
    if(sum==n)
    {
        printf("\n It is a strong number");
    }
    else
    {
        printf("\n It is not a strong number");
    }
    return 0;
}