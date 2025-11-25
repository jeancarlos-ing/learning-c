#include <stdio.h>

// Write a program to check the equivalence of two numbers entered by the user.

int main()
{
  int x, y;
  printf("\nEnter the first number: ");
  scanf("%d", &x);
  printf("\nEnter the second number: ");
  scanf("%d", &y);
  if (x - y == 0)
  {
    printf("\nThe two numbers are equivalent");
  }
  else
  {
    printf("\nThe two numbers are not equivalent");
  }
  return 0;
}