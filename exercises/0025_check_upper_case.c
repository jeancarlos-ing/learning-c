#include<stdio.h>
#include<ctype.h>

// Write a program to check whether the given character is a upper case letter or not.

int main()
{
    char ch = 'A';
    if(isupper(ch)) {
        printf("The given character is a upper case letter");
    } else {
        printf("The given character is a lower case letter");
    }
    return 0;
}
