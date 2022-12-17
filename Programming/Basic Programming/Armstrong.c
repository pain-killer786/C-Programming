/*Write a program to check whether the number is armstrong number or not.*/

#include<stdio.h>
#include<math.h>

int main()
{
    int num,q,rem,count=0,result=0; 
    
    
    printf("\n Enter a number");
    scanf("%d", &num);
    
    q=num;
    
    // Store the number of digits of num in n
    for(q=num; q!=0; ++count)
    {
        q/=10;
    }
    
    for(q=num;q!=0;q/=10)
    {
        rem=q%10;
 
        // Store the sum of the power of individual digits in result
        result+=pow(rem,count);
    }
    
    // if num is equal to result, the number is Armstrong number
    if(result==num)
    {
        printf("\n %d is an Armstrong Number",num);
    }
    else
    {
        printf("\n %d is not an Armstong Number",num);
    }
    return 0;
}