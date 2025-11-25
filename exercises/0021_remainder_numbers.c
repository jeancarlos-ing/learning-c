#include<stdio.h>

// Write a program to print the reaminder of two numbers entered by user.

int main() {
  int a, b, c;
  printf("\nEnter the first number: ");
  scanf("%d", &a);
  printf("\nEnter the second number: ");
  scanf("%d", &b);
  c = a%b;
  printf("\n The remainder of %d and %d is: %d",  a, b, c);
  return 0;
}
