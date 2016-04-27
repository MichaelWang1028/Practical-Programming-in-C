#include <stdio.h>
#include "shell_sort.h"
#include "util.h"

int main()
{
  printf("Before sorting:\n");
  print_array(array, array_size(array));

  shellsort();

  printf("After sorting:\n");
  print_array(array, array_size(array));

  return 0;
}
