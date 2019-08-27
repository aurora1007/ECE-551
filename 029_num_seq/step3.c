// This file is for Step 3.
// You should do
//  Step 3 (A): write seq3
//  Step 3 (B): write main to test seq3
//  Step 3 (C): write countEvenInSeq3Range
//  Step 3 (D): add test cases to main to test countEvenInSeq3Range
//
// Be sure to #include any header files you need!

#include <stdio.h>
#include <stdlib.h>

int seq3(int x, int y) {
  int result;
  result = 6 + (y - 3) * (x + 2);
  return result;
}

int countEvenInSeq3Range(int xLow, int xHi, int yLow, int yHi) {
  int i, j;
  int count = 0;
  for (i = xLow; i < xHi; i++) {
    for (j = yLow; j < yHi; j++) {
      if (seq3(i, j) % 2 == 0) {
        count++;
      }
    }
  }
  return count;
}

int main(void) {
  printf("seq3(%d, %d) = %d\n", 3, 5, seq3(3, 5));
  printf("seq3(%d, %d) = %d\n", -5, 4, seq3(-5, 4));
  printf("seq3(%d, %d) = %d\n", 2, 3, seq3(2, 3));
  printf("seq3(%d, %d) = %d\n", 4, -1, seq3(4, -1));
  printf(
      "countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 0, 3, countEvenInSeq3Range(0, 2, 0, 3));
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n",
         2,
         6,
         -5,
         0,
         countEvenInSeq3Range(2, 6, -5, 0));

  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n",
         -4,
         -2,
         -3,
         3,
         countEvenInSeq3Range(-4, -2, -3, 3));

  return 0;
}
