#include<stdio.h>
int main()
{
	int n,i,j,k;
    printf("\n Enter the value of n");
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		for(k=1;k<n;k++)
		{
			printf(" ");
			for (j=1;j<i+1;j++)
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
