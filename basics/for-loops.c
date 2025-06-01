/*
    For Loops in C

    Overview:
    ---------
    For loops allow you to repeat a block of code a specific number of times.

    Syntax:
    -------
        for (initialization; condition; increment) {
            // code to repeat
        }

    Example:
        for (int i = 0; i < 10; i++) {
            printf("%d\n", i);
        }

    For loops are often used to iterate over arrays.
*/

#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int factorial = 1;
    int i;

    // Calculate the factorial of 10 (10! = 1*2*3*...*10)
    for (i = 0; i < 10; i++)
    {
        factorial *= array[i]; // Multiply each element to the running product
    }

    // Print the result
    printf("10! is %d.\n", factorial);

    return 0;
}