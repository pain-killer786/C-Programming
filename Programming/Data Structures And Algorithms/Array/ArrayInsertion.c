#include<stdio.h>
#define max 100
int main()
{
	int a[max],size,i,num,pos;
	printf("Enter the number of elements of the array");
	scanf("%d", &size); // & is address operator
    if (size>max)
    {
        printf("Overflow Condition");
    }
    else
    {
        for(i=0;i<size;i++)
        {
            printf("Enter the element of Array");
            scanf("%d", &a[i]);
        }
        printf("Enter the Data You want to insert");
        scanf("%d",&num);
        printf("Enter the position You want to insert");
        scanf("%d",&pos);
        for(i=size-1;i>=pos-1;i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=num;
        size++;
        for(i=0;i<size;i++)
        {
            printf(" %d", a[i]);
        }
    }
    return 0;
}