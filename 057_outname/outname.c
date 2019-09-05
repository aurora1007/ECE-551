#include "outname.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * suffix = ".counts";
  int length = strlen(inputName);
  int total_length = length + strlen(suffix) + 1;
  char * outputName = malloc(total_length * sizeof(*outputName));
  int i;
  for (i = 0; i < length; i++) {
    outputName[i] = inputName[i];
  }
  for (int j = i; j < total_length; j++) {
    outputName[j] = suffix[j - i];
  }

  return outputName;
}
