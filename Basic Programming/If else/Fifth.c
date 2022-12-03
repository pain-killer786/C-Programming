#include<stdio.h>
int main()
{
	int a;
	printf("\n Enter a number:");
	scanf("%d", &a);
	if (a%2==0)
	{
		printf("\n Even number");
	}
	else
	{
		printf("\n Odd number");
	}
	return 0;
}