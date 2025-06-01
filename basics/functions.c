/*
    Functions in C

    Overview:
    ---------
    Functions are reusable blocks of code that perform a specific task.

    Syntax:
    -------
        return_type function_name(parameter_list) {
            // function body
        }

    Example:
        int add(int a, int b) {
            return a + b;
        }

    Functions can return a value or be void (no return value).
    Arguments are passed by value (a copy is made).
*/

#include <stdio.h>

/*
    print_big function:
    -------------------
    - Receives an integer 'number'.
    - Prints "<number> is big" if the number is greater than 10.
*/
void print_big(int number);

int main()
{
    int array[] = {1, 11, 2, 22, 3, 33};
    int i;

    // Loop through the array and call print_big for each element
    for (i = 0; i < 6; i++)
    {
        print_big(array[i]);
    }
    return 0;
}

void print_big(int number)
{
    if (number > 10)
    {
        printf("%d is big\n", number);
    }
}