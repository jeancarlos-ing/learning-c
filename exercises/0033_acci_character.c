#include<stdio.h>

// Write a program to print the ASCII value of the given character.

int main()
{
  char ch;
  printf("Enter any character: ");
  scanf("%c", &ch);
  printf("The ASCII value of %c is: %d", ch, ch);
  return 0;
}

