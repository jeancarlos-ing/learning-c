/*
    Conditions in C

    Overview:
    ---------
    Conditional statements allow programs to make decisions based on certain conditions.

    if statement:
    -------------
        if (expression) {
            // code if expression is true
        }

    else and else if:
    -----------------
        if (a < b) {
            // code if a is less than b
        } else if (a == b) {
            // code if a equals b
        } else {
            // code if a is greater than b
        }

    Logical operators:
    -----------------
        &&  AND
        ||  OR
        !   NOT

    Example:
        if (a < b && c > b) { ... }
*/

#include <stdio.h>

/*
    guessNumber function:
    ---------------------
    - Receives an integer 'guess'.
    - Compares 'guess' to the target value (555).
    - Prints feedback if the guess is too low, too high, or correct.
*/
void guessNumber(int guess)
{
    if (guess < 555)
    {
        printf("Your guess is too low.\n");
    }
    else if (guess > 555)
    {
        printf("Your guess is too high.\n");
    }
    else
    {
        printf("Correct. You guessed it!\n");
    }
}

int main()
{
    // Test the guessNumber function with different values
    guessNumber(500); // Output: too low
    guessNumber(600); // Output: too high
    guessNumber(555); // Output: correct
    return 0;
}