#include<stdio.h>

// Write a program to print the product of the first 10 digits.

int main() {
	int i, product = 1;
	for(i=1; i<=10; i++){
		product = product*i;
	}
	printf("The product of the first 10 digits is: %d", product);
return 0;
}
