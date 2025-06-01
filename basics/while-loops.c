/*
    While Loops in C

    Overview:
    ---------
    A while loop repeats a block of code as long as a condition is true.

    Syntax:
    -------
        while (condition) {
            // code to repeat
        }

    Example:
        int n = 0;
        while (n < 10) {
            n++;
        }

    Loop Control:
    -------------
    - break: Exit the loop immediately.
    - continue: Skip the rest of the loop and start the next iteration.
*/

#include <stdio.h>

int main()
{
    int array[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
    int i = 0;

    // Print array elements that are >= 5 and <= 10
    while (i < 10)
    {
        if (array[i] < 5)
        {
            i++;
            continue; // Skip values less than 5
        }

        if (array[i] > 10)
        {
            break; // Stop if value is greater than 10
        }

        printf("%d\n", array[i]); // Print the value if it is between 5 and 10
        i++;
    }

    return 0;
}
