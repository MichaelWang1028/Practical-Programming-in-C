#include <stdio.h>
#include "util.h"

void print_array(int *array, int size)
{
  printf("{");
  for (int i = 0; i < size - 1; i++) {
    printf("%d, ", *(array + i));
  }
  printf("%d}\n", *(array + size - 1));
}
