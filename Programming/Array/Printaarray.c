#include<stdio.h>
#define max 100
int main()
{
	int a[max],n,i;
	printf("Enter the number of elements of the array");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element of Array");
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++)
	{
		printf(" %d", a[i]);
	}
	return 0;
}
