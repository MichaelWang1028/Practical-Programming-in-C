#include "shell_sort.h"

int array[6] = {4, 0, 2, 1, 3, 5};

void shift_element_by_gap(unsigned int i, unsigned int gap)
{
  int i_value = array[i];
  for (; i && array[i - gap] > i_value; i -= gap) {
    array[i] = array[i - gap];
  }
  array[i] = i_value;
}

void shell_sort() {
  unsigned int gap , i , len = array_size(array) ;

  for (gap = len / 2 ; gap > 0 ; gap /= 2 ) {
    for (i = gap; i < len; i += gap) {
      if (array[i - gap] > array[i]) {
        shift_element_by_gap(i, gap);
      }
    }
  }
}
