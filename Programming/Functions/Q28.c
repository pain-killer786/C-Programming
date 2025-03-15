// Write a function that prints Namaste if the user is Indian and Bonjour if the user is French

#include<stdio.h>

void Indian();
void French();

int main()
{
    char ch;
    printf("Enter i or f");
    scanf("%c", &ch);
    
    if(ch=='i')
    {
        Indian();
    }
    else if (ch=='f')
    {
        French();
    }
    return 0;
}

void Indian()
{
    printf("Namaste");
}

void French()
{
    printf("Bonjour");
}