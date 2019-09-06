#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "counts.h"
#include "kv.h"
#include "outname.h"

void stripNewline(char * str) {
  char * p = strchr(str, '\n');
  if (p != NULL) {
    *p = '\0';
  }
}

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  size_t sz = 0;
  char * one_line = NULL;

  FILE * f = fopen(filename, "r");
  if (f == NULL) {
    fprintf(stderr, "cannot open input file:%s\n", filename);
    return NULL;
  }

  counts_t * create = createCounts();

  while (getline(&one_line, &sz, f) >= 0) {
    stripNewline(one_line);
    addCount(create, lookupValue(kvPairs, one_line));
    free(one_line);
    one_line = NULL;  //It is quite important to initialize one_line after using it
  }
  free(one_line);  //It is important to free the last one_line which contains -1
  fclose(f);
  return create;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if (argc < 3) {
    fprintf(stderr, "improper command line input\n");
    return EXIT_FAILURE;
  }
  //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv = readKVs(argv[1]);
  if (kv == NULL) {
    fprintf(stderr, "cannot read KV pairs\n");
    freeKVs(kv);
    return EXIT_FAILURE;
  }
  //count from 2 to argc (call the number you count i)
  for (int i = 2; i < argc; i++) {
    //count the values that appear in the file named by argv[i], using kv as the key/value pair

    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    if (c == NULL) {
      fprintf(stderr, "cannot open file %s\n", argv[i]);
      freeCounts(c);
      freeKVs(kv);
      return EXIT_FAILURE;
    }
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);
    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");  //note that it should be write, not read
    //print the counts from c into the FILE f
    printCounts(c, f);
    //close f
    fclose(f);

    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }
  //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
