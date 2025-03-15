// Write two finctions one to print "Hello" and Other to print "Good Bye".

#include<stdio.h>

void Hello();
void GoodBye();

int main()
{
    Hello();
    GoodBye();
    return 0;
}

void Hello()
{
    printf("Hello\n");
}

void GoodBye()
{
    printf("Goodbye");
}