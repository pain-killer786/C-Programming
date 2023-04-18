#include<stdio.h>
#include<conio.h>
float f(float x, float y)
{
    return ((x*x)+(y*y));
}

void main()
{
    float xn,xo,yo,yn,h,k1,k2,k3,k4;
    int i,n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    printf("Enter the value of xo,yo,xn:\n");
    scanf("%f%f%f",&xo,&yo,&xn);

    h=(xn-xo)/n;
    for(i=0;i<n;i++)
    {
        k1=h*f(xo,yo);
        k2=h*f((xo+h/2),(yo+k1/2));
        k3=h*f((xo+h/2),(yo+k2/2));
        k4=h*f((xo+h),(yo+k3));
    }

    yn=yo+(k1+2*k2*k3+k4)/6;
    printf("The value of 2nd order is %f", yn);
    getch();
}
