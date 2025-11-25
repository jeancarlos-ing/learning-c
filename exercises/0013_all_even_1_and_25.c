#include <stdio.h>

// Write a program that prints all even numbers between 1 and 25.

int main()
{
	printf("Even numbers between 1 to 25:\n");
	for (int i = 1; i <= 25; i++)
	{
		if (i % 2 == 0)
		{
			printf("%d", i);
		}
	}
	return 0;
}
