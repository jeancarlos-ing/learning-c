#include<stdio.h>
#include<ctype.h>

// Write a program to check whether a character is an alphabet or not.

int main() {
  int a =2;
  if(isalpha(a)) {
    printf("The character a is an alphabet");
  } else {
    printf("The character is not an alphabet");
  }
  return 0;
}
