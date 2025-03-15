#include<stdio.h>
int main()
{
	int a,b,c;
	printf("\n Enter choice: 1 for addition. 2 for substraction. 3 for multipilication.");
	scanf("%d", &a);
	if (a==1)
	{
        printf("\n Enter the values of b and c");
		scanf("%d %d", &b, &c);
		int sum = b+c;
		printf("%d",sum);
	}
	else if (a==2)
	{
        printf("\n Enter the values of b and c");
		scanf("%d &d", &b, &c);
		int diff= b-c;
		printf("%d",diff);
	}
	else if (a==3)
	{
        printf("\n Enter the values of b and c");
		scanf("%d %d", &b, &c);
		int prod=b*c;
		printf("%d",prod);
	}
	else
	{
		printf("\n Invalid Choice");
	}
	return 0;
}