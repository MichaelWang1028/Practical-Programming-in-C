#include <stdio.h>
#include "shell_sort.h"
#include "../util/util.h"

int main(void)
{
  puts("Before sorting");
  print_array(array, array_size(array));
  shell_sort();
  puts("After sorting");
  print_array(array, array_size(array));

  return 0;
}
