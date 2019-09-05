#include "kv.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
kvpair_t * readAPair(FILE * f) {
  kvpair_t * pair = malloc(sizeof(*pair));
  size_t sz = 0;
  char * line = NULL;
  ssize_t lenStr = getline(&line, &sz, f);  //get the length of one line
  int len1 = strchr(line, '=') - line;
  int len2 = lenStr - len1 - 2;
  pair->key = strndup(line, len1);
  pair->value = strndup(line + len1 + 1, len2);
  free(line);
  return pair;
}

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname, "r");

  if (f == NULL) {
    fprintf(stderr, "cannot open file\n");
    return NULL;

  }  //could not open file->indicate failure

  kvarray_t * array = malloc(sizeof(*array));
  char mid;
  int numLines = 0;

  while (!feof(f)) {
    mid = fgetc(f);
    if (mid == '\n')
      numLines++;  //count the number of lines
  }

  fseek(f, 0, SEEK_SET);  //return back to the beginning of the file
  array->length = numLines;
  array->pair = malloc(array->length * sizeof(*array->pair));  //*array->>pair?

  for (int i = 0; i < array->length; i++) {
    array->pair[i] = readAPair(f);
  }
  fclose(f);
  return array;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    free((pairs->pair[i])->key);
    free((pairs->pair[i])->value);
    free(pairs->pair[i]);
  }
  free(pairs->pair);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for (int i = 0; i < pairs->length; i++) {
    printf("key = '%s' value = '%s'\n", (pairs->pair[i])->key, (pairs->pair[i])->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME

  for (int i = 0; i < pairs->length; i++) {
    if (!strcmp((pairs->pair[i])->key, key)) {
      return (pairs->pair[i])->value;
    }
  }
  return NULL;
}
