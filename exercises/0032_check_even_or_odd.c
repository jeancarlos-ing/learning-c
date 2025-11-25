#include<stdio.h>

// Write a program to check whether a entered number is even or odd.

int main() {
  int a;
  printf("Enter any number: ");
  scanf("%d", &a);
  if(a%2 == 0) {
    printf("The entered number is even");
  } else {
    printf("The entered number is odd");
  }
  return 0;
}
