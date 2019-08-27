// This file is for Step 2.
// You should do
//  Step 2 (A): write seq2
//  Step 2 (B): write main to test seq2
//  Step 2 (C): write sumSeq2
//  Step 2 (D): add test cases to main to test sumSeq2
//
// Be sure to #include any header files you need!
#include <stdio.h>
#include <stdlib.h>

int seq2(int x) {
  int result;
  int count1 = 1;
  int count2 = -1;
  int i;
  if (x == 0) {
    result = 1;
  }
  else if (x > 0) {
    for (i = 1; i < x + 1; i++) {
      count1 = count1 + 2 * (i + 1);
      result = count1;
    }
  }
  else if (x == -1) {
    result = -1;
  }
  else {
    for (i = 0; i > x + 1; i--) {
      count2 = count2 + 2 * (-i);
      result = count2;
    }
  }
  return result;
}

int sumSeq2(int low, int high) {
  int j;
  int sum1 = 0;
  int sum2;
  if (low > high) {
    sum2 = 0;
  }
  else {
    for (j = low; j < high; j++) {
      sum1 = sum1 + seq2(j);
      sum2 = sum1;
    }
  }
  return sum2;
}

int main(void) {
  int i = 0;
  for (i = -4; i < 11; i++) {
    printf("seq2(%d)=%d\n", i, seq2(i));
  }

  printf("sumSeq2(%d, %d)=%d\n", -8, 8, sumSeq2(-8, 8));
  printf("sumSeq2(%d, %d)=%d\n", 0, 2, sumSeq2(0, 2));
  printf("sumSeq2(%d, %d)=%d\n", 3, 6, sumSeq2(3, 6));
  printf("sumSeq2(%d, %d)=%d\n", 9, 7, sumSeq2(9, 7));

  return 0;
}
