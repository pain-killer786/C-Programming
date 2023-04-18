#include<stdio.h>
#include<conio.h>
float f(float x, float y)
{
    return ((x*x)+(y*y));
}

void main()
{
    float xn,xo,yo,yn,h,k1;
    int i,n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    printf("Enter the value of xo,yo,xn:\n");
    scanf("%f%f%f",&xo,&yo,&xn);

    h=(xn-xo)/n;
    for(i=0;i<n;i++)
    {
        k1=yo+h*f(xo,yo);
    }

    yn=k1;
    printf("The value of 1st order is %f", yn);
    getch();
}
