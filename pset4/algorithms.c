#include <stdio.h>

int ∗ linear_search(int val);


int main()
{
  int *px = linear_search(2);

  printf("%p", px);

  return 0;
}


int ∗ linear_search(int val)
{
  int x = 10;

  return &x;
}
