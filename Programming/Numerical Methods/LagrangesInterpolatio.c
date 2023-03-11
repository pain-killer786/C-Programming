#include<stdio.h>
#include<conio.h>
void main()
{
    float x[10],y[10],u,val=0,a;
    int i,j,n;
    printf("Output\n");
    printf("Number of Arguments\n");
    scanf("%d",&n);
    printf("Enter the value of x\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }
    printf("Enter the value of f(x)\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&y[i]);
    }
    printf("Value of X for which function value is determined");
    scanf("%f",&a);

    for(i=0;i<n;i++)
    {
        u=y[i];
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                u=u*(a-x[j])/(x[i]-x[j]);
            }
        }
        val=val+u;
    }
    printf("The value of f(%f)=%f",a,val);
    getch();
}