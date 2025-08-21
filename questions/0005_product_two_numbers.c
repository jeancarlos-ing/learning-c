#include<stdio.h>

// Write a program that accepts two numbers from the user and calculate the product of the two numbers.

int main(){
int a, b, mult;
printf("\nEnter the first number: ");
scanf("%d", &a);
printf("\nEnter the second number: ");
scanf("%d", &b);
mult = a*b;
printf("\nProduct of the above two numbers is: %d", mult);
return 0;
}
