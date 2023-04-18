#include<stdio.h>
#include<conio.h>
int main()
{
    float x0,y0,m=0,y,x,h,xn;
    int n;
    printf("\n Enter the step size");
    scanf("%d",&n);
    printf("\n Enter the values of x0,y0,xn");
    scanf("%f %f %f",&x0,&y0,&xn);
    h=(xn-x0)/n;
    y=(x0*x0)+(y0*y0);
    m=(y*h)+y0;
    printf("\n The value of f(%f) is %f", xn,m);
}