#include<stdio.h>
#include<ctype.h>

// Write a program to convert the lower case letter to upper case letter.

int main()
{
  char ch = 'a';
  char b = toupper(ch);
  printf("Lower case letter '%c' is converted to Upper case letter '%c'", ch, b);
  return 0;
}
