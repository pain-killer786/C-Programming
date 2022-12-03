#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two numbers");
	scanf("%d%d",&a,&b);
	int t=a;
	a=b;
	b=t;
	printf("%d %d", a, b);
    return 0;
}
