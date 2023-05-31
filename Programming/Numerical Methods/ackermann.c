#include<stdio.h>

int A (int m,int n);


int main(){


int m,n;
printf("Enter the Two Number :: \n");
scanf("%d%d",&m,&n);
printf("%d",A(m,n));


}
int A(int m,int n){

if (m==0)
{
    return n+1;/* code */
}
else if(n==0){
return A(m-1,1);
}
else if(m==0 && n==0){
return A(m-1,A(m,n-1));

}


}