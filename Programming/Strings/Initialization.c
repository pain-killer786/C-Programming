/*It is an array of Characters
Syntax:- char string_name[size];
*/
#include<stdio.h>
int main()
{
    char s1[10];
    printf("Enter String: ");
    scanf("%s",s1); //Usage of scanf prints character until it encounters a whitespace, so it is a drawback
    printf("%s",s1);
    gets(s1);////Usage of scanf prints character till the last
    //Buffer Overflow :- if the size of the character array is less than the input data, gets will try to overwrite the data beyond the allocated memory, which is very risky as it may contain some important data of other programs
    puts(s1);
    //strlen is used to count the length of the string excluding the null operator.
    //strcat() is used to concatenate two strings
    //strcmp() is used to compare two strngs
    //strrev() is used to reverse the string
}