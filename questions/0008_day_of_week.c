#include<stdio.h>

// Write a program that reads an integer between 1 and 7 and print the day of the week in English.

int main() {
	int day;
	printf("\nEnter a number between 1 to 7 to get the day name: ");
	scanf("%d", &day);
	switch(day) {
		case 1: printf("Monday\n"); break;
		case 2: printf("Tuesday\n"); break;
		case 3: printf("Wednesday\n"); break;
		case 4: printf("Trusday\n"); break;
		case 5: printf("Friday\n"); break;
		case 6: printf("Saturday\n"); break;
		case 7: printf("Sunday\n"); break;
		default : printf("Enter a number between 1 to 7.");
	};
	return 0;
}

