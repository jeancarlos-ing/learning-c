/*
    Functions in C

    Overview:
    ---------
    Functions are reusable blocks of code that perform a specific task.

    Syntax:
    -------
        return_type function_name(parameter_list) {
            .. function body
        }

    Example:
        int add(int a, int b) {
            return a + b;
        }

    Functions can return a value or be void (no return value).
    Arguments are passed by value (a copy is made).
*/

#include <stdio.h>

/* Function declaration */
void print_big(int number);

int main()
{
    int array[] = {1, 11, 2, 22, 3, 33};
    int i;

    // Call print_big for each element in the array
    for (i = 0; i < 6; i++)
    {
        print_big(array[i]);
    }
    return 0;
}

/* Function definition: prints if a number is big (>10) */
void print_big(int number)
{
    if (number > 10)
    {
        printf("%d is big\n", number);
    }
}