#include<stdio.h>
#include<conio.h>
float f(float x, float y)
{
    return ((x*x)+(y*y));
}

void main()
{
    float xn,xo,yo,yn,h,k1,k2;
    printf("Enter the value of xo,yo,xn respectively:\n");
    scanf("%f%f%f",&xo,&yo,&xn);

    h=(xn-xo);
    k1=h*f(xo,yo);
    k2=h*f(xo+h,yo+h*f(xo,yo));

    yn=yo+(k1+k2)/2;
    printf("The value of 2nd order is %f", yn);
    getch();
}
