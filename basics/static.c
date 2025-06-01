/*
    Static Keyword in C

    Overview:
    ---------
    The 'static' keyword in C is used to preserve the value of a variable between function calls,
    or to restrict the visibility of a function or variable to the current file.

    This example demonstrates how a static variable inside a function retains its value
    between multiple calls to that function.
*/

#include <stdio.h>

/*
    sum function:
    -------------
    - Takes an integer 'num' as input.
    - Uses a static variable 'count' to keep a running total.
    - Each time sum() is called, 'num' is added to 'count'.
    - The updated total is returned.
    - Because 'count' is static, its value is preserved between calls.
*/
int sum(int num)
{
    static int count = 0; // Static variable, retains its value between calls
    count += num;         // Add the input number to the running total
    return count;         // Return the current total
}

int main()
{
    // Call sum() with different values and print the result each time
    printf("%d ", sum(55));  // Output: 55 (count = 0 + 55)
    printf("%d ", sum(45));  // Output: 100 (count = 55 + 45)
    printf("%d\n", sum(50)); // Output: 150 (count = 100 + 50)
    return 0;
}