#include "insertion.h"

int array[5] = {4, 0, 2, 1, 3};


void shift_element(int i)
{
  int i_value = array[i];
  for (; i && array[i - 1] > i_value; i--) {
    array[i] = array[i - 1];
  }
  array[i] = i_value;
}

void insertion_sort()
{
  for (int i = 1; i < array_size(array); i++) {
    if (array[i - 1] > array[i]) {
      shift_element(i);
    }
  }
}
