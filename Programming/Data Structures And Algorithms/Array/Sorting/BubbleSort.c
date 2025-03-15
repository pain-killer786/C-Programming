#include<stdio.h>
#define max 100
int main()
{
	int a[max], n, i, j, temp;
	printf("Enter the number of elements of the array\n");
	scanf("%d", &n);
	for(i=0;i<=n;i++)
	{
		printf("Enter the elements of the array\n");
		scanf("%d", &a[i]);
	}
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Sorted array is:");
	for(i=0;i<=n;i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
