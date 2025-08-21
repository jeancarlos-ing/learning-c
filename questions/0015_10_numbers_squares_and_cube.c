#include<stdio.h>

// Write a program to print the first 10 numbers starting from one together with their squares and cubes.

int main() {
	for (int i=1; i<=10; i++) {
		printf("Number = %d its square = %d its cube = %d\n", i, i*i, i*i*i);
	}
	return 0;
}
