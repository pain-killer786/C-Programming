#include<stdio.h>
int main()
{
	int a, b;
	printf("\n Enter two numbers:");
	scanf("%d %d", &a,&b);
	if (a==b)
	{
		printf("\n Both numbers are equal.");
	}
	else
	{
		printf("\n Not");
	}
	return 0;
}
