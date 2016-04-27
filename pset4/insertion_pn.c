#include "insertion_pn.h"

int array[5] = {4, 0, 2, 1, 3};

void shift_element(int *pElement)
{
  int i_value = *pElement;

  for (; array < pElement && *(pElement - 1) > i_value; pElement--) {
    *pElement = *(pElement - 1);
  }
  *pElement = i_value;
}

void insertion_sort()
{
  for (int *pElement = array + 1; pElement < array + array_size(array); pElement++) {
    if (*pElement < *(pElement - 1)) {
      shift_element(pElement);
    }
  }
}
