/*
    Variables and Types in C

    Overview:
    ---------
    C has several basic types:

    - Integers: Whole numbers, can be positive or negative (char, int, long, long long)
    - Unsigned Integers: Only positive numbers (unsigned int, etc.)
    - Floating Point: Real numbers with fractions (float, double)
    - Structures: Custom types (explained later)

    Note:
    -----
    C does not have a built-in boolean type. Usually, 0 is false and any non-zero value is true.

    Defining Variables:
    -------------------
        int a = 0, b = 1, c = 2;
        a = b - c + d * e;

    Printing Variables:
    -------------------
        printf("%d", a); // Prints an integer
*/

#include <stdio.h>

int main()
{
    int a = 3;         // Integer variable
    float b = 4.5;     // Float variable
    double c = 5.25;   // Double variable (more precision than float)
    float sum = a + b + c; // Sum of the variables (implicit conversion to float)

    printf("The sum of a, b, and c is %f.\n", sum);
    return 0;
}
