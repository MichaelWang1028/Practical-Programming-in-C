#include <stdio.h>
#include "sort_pointers.h"

int array[5] = {4, 3, 1, 5, 2};
int * pointer_array[5];

int main()
{
  unsigned int length = array_length(array);

  for (unsigned int i = 0; i < length; i++) {
    pointer_array[i] = (array + i);
  }

  puts("array:");
  print_array(array, length);
  puts("Insertion sort");
  insertion_sort();
  puts("sorted array:");
  print_pointer_array(pointer_array, length);
  puts("array:");
  print_array(array, length);

  return 0;
}

void shift_element(unsigned int i)
{
  int *pvalue;
  for (pvalue = pointer_array[i]; i && *pointer_array[i - 1] > *pvalue; i--) {
    pointer_array[i] = pointer_array[i - 1];
  }
  pointer_array[i] = pvalue;
}

void insertion_sort()
{
  for (unsigned int i = 1; i < array_length(pointer_array); i++) {
    if (*pointer_array[i] < *pointer_array[i - 1]) {
      shift_element(i);
    }
  }
}

void print_array(int *array, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++) {
    printf("%d\t", *(array + i));
  }
  puts("");
}

void print_pointer_array(int **array, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++) {
    printf("%d\t", **(array + i));
  }
  puts("");
}
