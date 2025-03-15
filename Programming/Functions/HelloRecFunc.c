#include<stdio.h>

void printHello(int count);

int main()
{
    printHello(10);
    return 0;
}

//Recursive function
void printHello(int count)
{
    if(count==0)
    {
        return;
    }
    printf("Hello World!\n");
    printHello(count-1);
}