// Write a program to check whether a number is prime or not.

#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,q,s;
    printf("\n Enter a number");
    scanf("%d", &n);

    q=n;
    for(i=1;i<=sqrt(q);i++)
    {
        s=q%i;
    }

    if(s!=0)
    {
        printf("\n The number is prime number.");
    }
    else
    {
        printf("\n The number is not a prime number.");
    }
    
    return 0;
}