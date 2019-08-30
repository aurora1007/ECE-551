#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

void run_check(int * array, size_t n, size_t expected_length) {
  size_t result = maxSeq(array, n);
  if (result != expected_length) {
    exit(EXIT_FAILURE);
  }
}

int main(void) {
  int array1[10] = {1, 2, 1, 3, 5, 8, 2, 4, 6, 9};
  run_check(array1, 10, 4);

  int array2[0] = {};
  run_check(array2, 0, 0);

  int array3[5] = {0, 0, 0, 0, 0};
  run_check(array3, 5, 1);

  int array4[5] = {-100, -99, 0, 99, 100};
  run_check(array4, 5, 5);

  int array5[5] = {-1, 1, -1, 1, -1};
  run_check(array5, 5, 2);

  int array6[6] = {1, 2, 3, -3, -2, -1};
  run_check(array6, 6, 3);

  return EXIT_SUCCESS;
}
