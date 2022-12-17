#include<stdio.h>
int main()
{
    int n,d,r=0,q;
    printf("\n Enter a number");
    scanf("%d",&n);
    q=n;
    while (q!=0)
    {
        d=q%10;
        r=r*10+d;
        q=q/10;
    }
    if(r==n)
    {
        printf("\n Palindrome number");
    }
    else
    {
        printf("\n Not palindrome");
    }
    return 0;
}