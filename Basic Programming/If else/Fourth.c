#include<stdio.h>
int main()
{
	int a;
	printf("\n Enter a number:");
	scanf("%d", &a);
	if (a<0)
	{
		printf("\n Negative");
	}
	else if(a>0)
	{
		printf ("\n Positive");
	}
	else
	{
		printf("\n Zero");
	}
	return 0;
}