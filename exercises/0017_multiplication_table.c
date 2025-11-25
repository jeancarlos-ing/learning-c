#include <stdio.h>

// Write a program to print the multiplication table of a number
// entered by the user.

int main()
{
	int n, i;
	printf("Enter any number: ");
	scanf("%d", &n);
	for (i = 1; i <= 10; i++)
	{
		printf("%d * %d = %d\n", n, i, n * i);
	}
	return 0;
}
