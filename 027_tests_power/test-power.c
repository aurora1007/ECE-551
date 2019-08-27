#include <stdio.h>
#include <stdlib.h>
unsigned power(unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans) {
  unsigned result = power(x, y);
  if (result != expected_ans)
    return exit(EXIT_FAILURE);
}

int main(void) {
  run_check(0, 0, 1);
  run_check(1, 1, 1);
  run_check(0, -1, 0);
  run_check(0, 2, 0);
  run_check(1, 345, 1);
  run_check(-2, 2, 4);
  run_check(2, 3, 8);
  run_check(-2, 3, -8);
  return EXIT_SUCCESS;
}
