#include <stdio.h>

int main() {
    int  a, b, c;
    

   printf("Enter all the 3 Number To be Tested");
        scanf("%d %d %d", &a, &b, &c);

        if (a > b && a > c) {
            if(b>c){
                printf(" The Largest number is=%d",b);
            }
            else 
            {
                printf("The Largest Number is=%d",c);
            }
                  
           
        } 

        else if (b > a && b > c) {
              if(a>c){
                printf("The Largest Number is=%d",a);
              }
              else{
                 printf("The Largest Number is=%d",c);
              }

        }
         else if (c> a && c > b) {
              if(a>b){
                printf("The Largest Number is=%d",b);
              }
              else{
                 printf("The Largest Number is=%d",a);
              }

       
        }
    

    return 0;
}
