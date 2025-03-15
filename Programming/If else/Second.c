#include<stdio.h>
int main()
{
	int a, b, c;
	printf("\n Enter three numbers:");
	scanf("%d %d %d", &a, &b, &c);
	if (a>b && a>c)
	{
		printf("\n The Greatest number is: %d", a);
	}
	else if (b>a && b>c)
	{
		printf("\n The Greatest number is: %d", b);
	}
	else 
	{
		printf("\n The Greatest number is: %d", c);
	}
	return 0;
}
