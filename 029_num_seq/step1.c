// This file is for Step 1.
// You should do
//  Step 1 (A): write seq1
//  Step 1 (B): write main to test seq1
//  Step 1 (C): write printSeq1Range
//  Step 1 (D): add test cases to main to test printSeq1Range
//
// Be sure to #include any header files you need!

#include <stdio.h>
#include <stdlib.h>

int seq1(int x) {
  return -3 + 4 * x;
}

void printSeq1Range(int low, int high) {
  int j;
  if (high > low) {
    for (j = low; j < high - 1; j++) {
      printf("%d, ", seq1(j));
    }
    printf("%d\n", seq1(high - 1));
  }
  else {
    printf("\n");
  }
}

int main(void) {
  int j;
  for (j = -4; j < 8; j++) {
    printf("seq1(%d)=%d\n", j, seq1(j));
  }

  printf("printfSeq1Range(-8, 8)\n");
  printSeq1Range(-8, 8);

  printf("printfSeq1Range(5, 15)\n");
  printSeq1Range(5, 15);

  printf("printfSeq1Range(0, 0)\n");
  printSeq1Range(0, 0);

  printf("printfSeq1Range(9, 0)\n");
  printSeq1Range(9, 0);

  return 0;
}
