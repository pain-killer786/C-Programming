#include<stdio.h>
#include<conio.h>

 void main(void){

 float num;
 int x=0;
 printf("Enter a number");
 scanf("%f",&num);
 if(num<0){
    while(num<-1){

    num=num+1;
    x=x-1;

    }
    if(num<=-0.5){
        printf("%d",x-1);
    }
    else{
        printf("%d",x);
    }


 }
 else{
    while(num>1){

    num=num-1;
    x=x+1;

    }
    if(num>=0.5){
        printf("%d",x+1);
    }
    else{
        printf("%d",x);
    }
 }

 }
