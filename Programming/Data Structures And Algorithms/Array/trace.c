#include<stdio.h>
#include<conio.h>
void main()
{
int a[5][5];
int r,c,i,j, trace=0;

printf("\nEnter same number of rows and columns");
scanf("%d %d", &r, &c);
printf("\nEnter total %d elements", r*c);
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(i==j)
trace=trace+a[i][j];
}
}
printf("\nThe trace of the martix is %d", trace);
getch();
}