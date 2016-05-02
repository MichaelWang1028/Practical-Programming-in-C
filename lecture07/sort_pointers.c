#include <stdio.h>
#include "sort_pointers.h"

int array[5] = {4, 3, 1, 5, 2};
int * sorted_array[5];

int main()
{
  unsigned int length = array_length(array);

  for (unsigned int i = 0; i < length; i++) {
    sorted_array[i] = (array + i);
  }

  puts("array:");
  print_array(array, length);
  puts("Insertion sort");
  insertion_sort();
  puts("sorted array:");
  print_sorted_array(sorted_array, length);
  puts("array:");
  print_array(array, length);

  return 0;
}

void shift_element(unsigned int i)
{
  int *pvalue;
  for (pvalue = sorted_array[i]; i && *sorted_array[i - 1] > *pvalue; i--) {
    sorted_array[i] = sorted_array[i - 1];
  }
  sorted_array[i] = pvalue;
}

void insertion_sort()
{
  for (unsigned int i = 1; i < array_length(sorted_array); i++) {
    if (*sorted_array[i] < *sorted_array[i - 1]) {
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

void print_sorted_array(int **array, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++) {
    printf("%d\t", **(array + i));
  }
  puts("");
}
