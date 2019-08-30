#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  size_t count = 1;
  size_t length1 = 0;
  size_t length2 = 0;
  size_t i;

  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    for (i = 1; i < n; i++) {
      if (array[i] > array[i - 1]) {
        count++;
        length1 = count;
      }
      else {
        if (count >= length2) {
          length2 = count;
        }
        count = 1;
      }
    }
  }
  if (length1 > length2) {
    length2 = length1;
  }
  return length2;
}
