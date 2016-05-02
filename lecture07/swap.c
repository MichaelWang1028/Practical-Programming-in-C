#include <stdio.h>
#include "swap.h"

int main()
{
  int x = 9;
  int y = 6;

  int *px = &x;
  int *py = &y;

  puts("Before swapping");
  printf("x = %d, y = %d\n", x, y);
  printf("*px = %d, *py = %d\n", *px, *py);

  swap(&x, &y);

  puts("After swapping x and y");
  printf("x = %d, y = %d\n", x, y);
  printf("*px = %d, *py = %d\n", *px, *py);

  swap_pointers(&px, &py);
  puts("After swapping now px and py");
  printf("x = %d, y = %d\n", x, y);
  printf("*px = %d, *py = %d\n", *px, *py);




  return 0;
}

void swap_pointers(int **a, int **b)
{
  int *temp = *a;
  *a = *b;
  *b = temp;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
