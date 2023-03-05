#include<stdio.h>
#include<conio.h>

int main()
{
    int n,i,j;
    float x[10],y[10][10],sum,p,u,temp;
    int fact(int);
    printf("\nhow many record you will be enter: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\n\nenter the value of x%d: ",i);
        scanf("%f",&x[i]);
        printf("\n\nenter the value of f(x%d): ",i);
        scanf("%f",&y[i][0]);
    }
    printf("\n\nEnter X for finding f(x): ");
    scanf("%f",&p);

    //*********** FORWARD DIFFERENCE TABLE ****************//

    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }

//*********** DISPLAYING FORWARD DIFFERENCE TABLE*********//

printf("\n_____________________________________________________\n");
printf("\n  x(i)\t   y(i)\t   y1(i)   y2(i)   y3(i)   y4(i)");
printf("\n_____________________________________________________\n");
for(i=0;i<n;i++)
{
printf("\n %.3f",x[i]);
for(j=0;j<n-i;j++)
{
printf("   ");
printf(" %.3f",y[i][j]);
}
printf("\n");
}

//***************** NEWTON'S FORWARD INTERPOLATION FORMULA *********//

u=(p-x[0])/(x[1]-x[0]);
sum=y[0][0];
temp=u;
for(i=1;i<n;i++)
{
sum=sum+(temp*y[0][i])/fact(i);
temp=temp*(u-i);
}

printf("\n\n f(%.2f) = %f ",p,sum); // VALUE OF f(x) at x
getch();
}

int fact(int n)
{
int i,fac=1;
if(n==0)
return(1);
for(i=n;i>=1;i--)
fac=fac*i;
return(fac);
}