#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rotate(FILE * f) {
  char matrix[10][12];
  char str[12];
  int line_no = 0;
  while (fgets(str, 12, f) != NULL) {
    if (line_no == 10) {
      fprintf(stderr, "Wrong number of lines.\n");
      exit(EXIT_FAILURE);
    }
    if (strchr(str, '\n') - str != 10) {
      fprintf(stderr, "Wrong number of characters in some line.\n");
      exit(EXIT_FAILURE);
    }
    strcpy(matrix[line_no++], str);
  }
  if (line_no != 10) {
    fprintf(stderr, "Wrong number of lines.\n");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      fprintf(stdout, "%c", matrix[9 - j][i]);
    }
    fprintf(stdout, "\n");
  }
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr, "Wrong number of arguments.\n");
    exit(EXIT_FAILURE);
  }
  FILE * file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Could not find this file\n");
    exit(EXIT_FAILURE);
  }

  rotate(file);

  fclose(file);

  return EXIT_SUCCESS;
}
