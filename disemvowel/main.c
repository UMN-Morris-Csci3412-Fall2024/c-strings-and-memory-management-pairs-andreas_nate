#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t size = 0;
  
  while (getline(&line, &size, stdin) > 0) {
    char *result = disemvowel(line);
    printf("%s\n", result);
    free(result); // Free the allocated memory for result
  }

  free(line); // Free the allocated memory for line
}