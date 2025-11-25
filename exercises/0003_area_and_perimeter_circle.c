#include <stdio.h>

// Write a program to compute the perimeter and area of a circle.

int main()
{
    int radius = 8;
    float perimeter = 2 * 3.14 * radius;
    printf("Perimeter of the circle is: %f cm\n", perimeter);
    float area = 3.14 * radius * radius;
    printf("Area of the circle is: %f square cm\n", area);
    return 0;
}
