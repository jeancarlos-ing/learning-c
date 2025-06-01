/*
    Conditions in C

    Overview:
    ---------
    Conditional statements allow programs to make decisions based on certain conditions.

    if statement:
    -------------
        if (expression) {
            .. code if expression is true
        }

    else and else if:
    -----------------
        if (a < b) {
            .. code if a is less than b
        } else if (a == b) {
            // code if a equals b
        } else {
            .. code if a is greater than b
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

// Function to give feedback on a guess
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
    guessNumber(500); // Too low
    guessNumber(600); // Too high
    guessNumber(555); // Correct
    return 0;
}