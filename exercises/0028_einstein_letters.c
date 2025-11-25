#include<stdio.h>

// Write a program to print the output:
// Einstein [0] = E
// Einstein [1] = I
// Einstein [2] = N
// Einstein [3] = S
// Einstein [4] = T
// Einstein [5] = E
// Einstein [6] = I
// Einstein [7] = N

int main() {
  char name [8] = {'E', 'I', 'N', 'S', 'T', 'E', 'I', 'N'};
  for (int i=0; i<8; i++) {
    printf("\nEinstein [%d] = %c", i, name[i]);
  }
  return 0;
}
