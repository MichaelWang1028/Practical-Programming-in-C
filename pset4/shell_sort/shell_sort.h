#ifndef _SHELL_SHORT_H_
#define _SHELL_SHORT_H_

#define array_size(array) sizeof(array) / sizeof(array[0])

extern int array[6];
void shift_element_by_gap(unsigned int i, unsigned int gap);
void shellsort();

#endif
