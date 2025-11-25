#include <stdio.h>

// Write a program to print the average of the elements in the array.

int main()
{
	int i, avg, sum = 0;
	int num[5] = {16, 20, 28, 60, 55};
	for (i = 0; i < 5; i++)
	{
		sum = sum + num[i];
		avg = sum / 5;
	}
	printf("Sum of the Elements in the array is: %d\n", sum);
	printf("Average of the elements in the array is: %d\n", avg);
	return 0;
}
