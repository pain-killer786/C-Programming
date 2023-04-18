#include<stdio.h>
#include<conio.h>
float f (float x)
{
    return(1/(1+(x*x)));
}
void main()
{
    float h,s=0.0,tr,x,a,b;
    int i,n;
    printf("\n Trapezoidal rule");
    printf("\n Enter the value of step size");
    scanf("%d",&n);
    printf("\nEnter the value of the upper limit and lower limit");
    scanf("%f %f", &a,&b);
    h=(b-a)/n;
    for(i=1;i<n;i++)
    {
        s=s+f(a+i*h);
    }
    tr=h*(f(a)+f(b)+2*s)/2;
    printf("\n Value of integration is %f",tr);
    getch();
}