#include<stdio.h>
#define max 100
int main()
{
    int m,n,i,j,a[max][max];
    printf("\n Enter the number of rows and columns of an 2D array:");
    scanf("%d %d", &m,&n);
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n The resultant Matrix is:-");
    for(i=0;i<m;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d ", a[i][j]);
        }        
    }
    return 0;
}