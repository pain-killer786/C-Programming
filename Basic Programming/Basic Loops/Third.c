#include<stdio.h>
int main()
{
	int n,prod=1,sum=0;
    printf("\n Enter the value of n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sum=sum+i;
		prod=prod*i;
		printf("%d %d\n",sum,prod);
	}
	return 0;
}
