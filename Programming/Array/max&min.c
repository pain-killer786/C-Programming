#include<stdio.h>
#include<conio.h>

void main(void){

int a[100],n,i,max,min,indmax,indmin;
printf("\n how many elements in the array?");
scanf("%d",&n);
printf("\n enter %d integer values",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\n Output");
for(i=0;i<n;i++)
printf("%d",a[i]);
max=a[0];
for(i=0;i<n;i++){
    if(a[i]>=max)
    {
       max = a[i];
        indmax=i;
    }
    if(a[i]<=min){
        min=a[i];
        indmin=i;
    }

    }
    printf("\n max of array =%d and corresponding index is %d ",max,indmax);
    printf("\n min of array =%d and corresponding index is %d ",min,indmin);







}

