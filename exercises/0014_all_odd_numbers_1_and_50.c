#include <stdio.h>

// Write a program that prints all odd numbers between 1 and 50.

int main()
{
	printf("Odd numbers between 1 to 50:\n");
	for (int i = 1; i <= 50; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d", i);
		}
	}
	return 0;
}
