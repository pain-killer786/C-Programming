#include<stdio.h>
#define max 100
int main()
{
	int a[max],size,i,num,pos;
	printf("Enter the number of elements of the array");
	scanf("%d", &size); // & is address operator
    
    for(i=0;i<size;i++)
    {
        printf("Enter the element of Array");
        scanf("%d", &a[i]);
    }
    
    printf("Enter the position You want to delete");
    scanf("%d",&pos);

    if (pos<=0 || pos>size)
    {
        printf("Invalid Position");
    }
    else
    {
        for(i=pos-1;i<size-1;i++)
        {
            a[i]=a[i+1];
        }
    } 
    size--;

    for(i=0;i<size;i++)
        {
            printf(" %d", a[i]);
        }
    return 0;
}
