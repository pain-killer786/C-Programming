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
    printf("\n Simpson's 1/3rd rule");
    printf("\n Enter the value of step size");
    scanf("%d",&n);
    printf("\n Enter the value of the upper limit and lower limit");
    scanf("%f %f", &a,&b);
    h=(b-a)/n;
    for(i=1;i<n;i++)
    {
        x=a+i*h;
        if(i%2==0)
        {
            s=s+2*(f(x));
        }
        else
        {
            s=s+4*f(x);
        }
    }
    tr=(h/3)*(f(a)+f(b)+s);
    printf("\n Value of integration is %f",tr);
    getch();
}