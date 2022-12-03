#include<stdio.h>
int main()
{
	int a;
	printf("\n Enter a number:");
	scanf("%d", &a);
	if (a%5==0 && a%2==0 || a%3==0)
	{
		printf("\n Divisible by 5 and 2 or 3:");
	}
	else
	{
		printf("\n Not divisible");
	}
	return 0;
}