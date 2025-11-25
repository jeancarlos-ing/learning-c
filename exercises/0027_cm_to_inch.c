#include<stdio.h>
#define x 2.54

// Write a program that takes a distance in centimeters and outputs the corresponding value in inches.

int main()
{
  double inch, cm;
  printf("Enter distance in cm: ");
  scanf("%lf", &cm);
  inch = cm / x;
  printf("\nDistance of %0.2lf cms is equal to %0.2lf inches", cm, inch);
  return 0;
}
