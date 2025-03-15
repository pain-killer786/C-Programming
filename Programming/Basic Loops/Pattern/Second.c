#include<stdio.h>
int main()
{
	int n,i,j;
    printf("\n Enter the value of n");
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<i+1;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
