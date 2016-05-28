#include <stdio.h>
#include "insertion.h"
#include "../util.h"

int main(void)
{
  puts("Before sorting");
  print_array(array, array_size(array));
  insertion_sort();
  puts("After sorting");
  insertion_sort();
}
