/*
    Arrays in C

    Overview:
    ---------
    Arrays are special variables that can hold multiple values of the same type, organized by index.
    Arrays in C are zero-based, meaning the first element is at index 0.

    Declaration:
    ------------
        int numbers[10]; // Declares an array of 10 integers

    Accessing Elements:
    -------------------
        numbers[0] = 10; // Assigns 10 to the first element
        printf("%d", numbers[0]); // Prints the first element

    Note:
    -----
    Arrays can only store one type of variable. Accessing a specific element is very efficient.
*/

#include <stdio.h>

int main()
{
    int average;
    int grades[3]; // Array to store 3 grades

    // Assign values to the grades array
    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;

    // Calculate the average of the 3 grades
    average = (grades[0] + grades[1] + grades[2]) / 3;

    // Print the result
    printf("The average of the 3 grades is: %d\n", average);

    return 0;
}