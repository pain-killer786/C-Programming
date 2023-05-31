#include<stdio.h>
#include<conio.h>

void main(){
int x,y,s,gcd=1;
printf("\n Enter The Two Number");
scanf("%d %d",&x,&y);
if(x>y){
s=y;}
else{
s=x;}
for( int i=1;i<=s;i++){
if(x%i==0 && y%i==0)
gcd=gcd*i;
}
printf("\n The Gcd is=%d",gcd);



}