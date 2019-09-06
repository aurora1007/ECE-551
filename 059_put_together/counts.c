#include "counts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * create = malloc(sizeof(*create));
  create->count_unknown = 0;
  create->sz_array = 0;
  create->array = NULL;

  return create;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  int match = 0;  //use to record whether name has been in any oneCount
  int i;
  if (name == NULL) {
    c->count_unknown++;
    return;
  }

  else {
    for (i = 0; i < c->sz_array; i++) {
      if (strcmp(name, (c->array[i])->One_name) == 0) {
        c->array[i]->times++;
        match++;
        break;
      }
    }

    if (match == 0) {
      c->sz_array++;
      int li = c->sz_array;

      c->array = realloc(c->array, (li) * sizeof(*c->array));
      c->array[li - 1] = malloc(sizeof(*(c->array[i - 1])));
      c->array[li - 1]->One_name = strdup(name);
      c->array[i]->times = 1;
    }
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for (int i = 0; i < c->sz_array; i++) {
    fprintf(outFile, "%s: %d\n", (c->array[i])->One_name, (c->array[i])->times);
  }
  if (c->count_unknown != 0) {
    fprintf(outFile, "<unknown> : %d\n", c->count_unknown);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for (int i = 0; i < c->sz_array; i++) {
    free(c->array[i]->One_name);
    free(c->array[i]);
  }
  free(c->array);
  free(c);
}
