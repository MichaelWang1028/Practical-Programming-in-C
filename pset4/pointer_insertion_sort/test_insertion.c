#include <stdio.h>
#include "insertion.h"
#include "../util/util.h"

int main()
{
  printf("Before sorting:\n");
  print_array(array, array_size(array));

  insertion_sort();

  printf("After sorting:\n");
  print_array(array, array_size(array));

  return 0;
}
