#include<stdio.h>
#include<ctype.h>

// Write a program to check whether the given character is a lower case letter or not.

int main()
{
    char ch = 'a';
    if(islower(ch)) {
        printf("The given character is a lower case letter");
    } else {
        printf("The given character is a upper case letter");
    }
    return 0;
}
