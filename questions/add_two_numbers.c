#include <stdio.h>
int main()
{
    int a, b, sum;
    printf("\nEnter the first number: ");
    scanf("%d", &a);
    printf("\nEnter the second number: ");
    scanf("%d", &b);
    sum = a + b;
    printf("\nSum of the above two numbers is: %d", sum);
    return 0;
}