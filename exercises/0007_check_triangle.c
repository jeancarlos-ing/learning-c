#include <stdio.h>

// Write a program that reads three floating values and check if it is possible to make a triangle with them. Also calculate the perimeter of the triangle if the entered values are valid.

int main()
{
  float x, y, z;
  printf("\nEnter the first number: ");
  scanf("%f", &x);
  printf("\nEnter the second number: ");
  scanf("%f", &y);
  printf("\nEnter the third number: ");
  scanf("%f", &z);

  if (x < (y + z) && y < (x + z) && z < (x + y))
  {
    printf("\nPerimeter of the triangle is: %f\n", x + y + x);
  }
  else
  {
    printf("\nIt is impossible to form a triangle.");
  }

  return 0;
}
