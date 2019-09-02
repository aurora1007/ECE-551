#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int maxf(int * array, size_t size) {
  int maxf = 0;
  size_t i = 0;
  for (i = 0; i < size; i++) {
    if (array[i] > array[maxf])
      maxf = i;
  }
  return 'a' + maxf;
}

void decipher(FILE * f) {
  int c;
  int array[26] = {0};
  int key;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      array[c - 'a']++;
    }
  }

  if (maxf(array, 26) - 'e' < 0) {
    key = maxf(array, 26) - 'e' + 26;
  }
  else
    key = maxf(array, 26) - 'e';
  fprintf(stdout, "%d\n", key);
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: inputFilename\n");
    return EXIT_FAILURE;
  }

  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Could not open file\n");
    return EXIT_FAILURE;
  }
  decipher(f);
  if (fclose(f) != 0) {
    perror("Failed to close the input file");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
