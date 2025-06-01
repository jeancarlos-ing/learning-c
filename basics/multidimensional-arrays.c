/*
    Multidimensional Arrays in C

    Overview:
    ---------
    Arrays can have more than one dimension. The most common is the two-dimensional array,
    which can be visualized as a table (rows and columns).

    Declaration:
    ------------
        int a[3][4]; // 3 rows, 4 columns

    Initialization:
    ---------------
        int a[3][4] = {
            {0, 1, 2, 3},
            {4, 5, 6, 7},
            {8, 9, 10, 11}
        };

    Accessing Elements:
    -------------------
        int val = a[2][3]; // Gets the value in the 3rd row, 4th column

    Program Description:
    --------------------
    This program demonstrates how to declare, initialize, and calculate the average of grades for two students,
    where each student has grades for five subjects, using a two-dimensional array.
*/

#include <stdio.h>

int main()
{
    int grades[2][5]; // 2 students, 5 subjects each
    float average;
    int i, j;

    // Assign grades for student 0
    grades[0][0] = 80;
    grades[0][1] = 70;
    grades[0][2] = 65;
    grades[0][3] = 89;
    grades[0][4] = 90;

    // Assign grades for student 1
    grades[1][0] = 85;
    grades[1][1] = 80;
    grades[1][2] = 80;
    grades[1][3] = 82;
    grades[1][4] = 87;

    // Calculate and print the average for each student
    for (i = 0; i < 2; i++)
    {
        average = 0;

        // Sum grades for student i
        for (j = 0; j < 5; j++)
        {
            average += grades[i][j];
        }

        average /= 5.0; // Calculate average for 5 subjects
        printf("The average marks obtained by student %d is: %.2f\n", i, average);
    }

    return 0;
}