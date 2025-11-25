#include<stdio.h>

// Write a program that will print all numbers between 1 to 50 which divided by a specified number and the remainder will be 2.

int main()
{
  int x, i;
  printf("Enter a number: ");
  scanf("%d", &x);
  for(i=1; i<=50; i++){
    if((i%x)==2){
      printf("%d\n", i);
    }
  }
  return 0;
}
