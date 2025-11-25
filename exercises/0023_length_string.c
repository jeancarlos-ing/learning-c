#include<stdio.h>
#include<string.h>

// Write a program to print the length of the entered strinig.

int main() {
    char str[1000];
    printf("Enter a string to calculate its length: ");
    scanf("%s", str);
    printf("The length of the entered string is: %ld", strlen(str));
    return 0;
}
