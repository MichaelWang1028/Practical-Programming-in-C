#ifndef SORT_POINTERS_H
#define SORT_POINTERS_H

#define array_length(array) ((sizeof(array) == 0) ? 0 : (sizeof(array) / sizeof(array[0])))

extern int array[5];
extern int * sorted_array[5];

void print_array(int *array, unsigned int length);
void shift_element(unsigned int i);
void insertion_sort();
void print_pointer_array(int **array, unsigned int length);

#endif
