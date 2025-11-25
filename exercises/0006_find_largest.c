#include <stdio.h>

// Write a program that accepts three numbers and find the largest of three

int main()
{
  int x, y, z;
  printf("\nEnter first number: ");
  scanf("%d", &x);
  printf("\nEnter second number: ");
  scanf("%d", &y);
  printf("\nEnter third number: ");
  scanf("%d", &z);

  // if x is greater than both y and z, x is the largest
  if (x >= y && x >= z)
    printf("\n%d is the largest number.", x);

  // if y is greater than both x and z, y is the largest
  if (y >= x && y >= z)
    printf("\n%d is the largest number.", y);

  // if z is greater than both x and y, z is the largest
  if (z >= x && z >= y)
    printf("\n%d is the largest number.", z);

  return 0;
}
