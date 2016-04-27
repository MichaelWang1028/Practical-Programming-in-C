#include <stdio.h>

int test_pointer(int *x, int *y, int z);

int main()
{
  int n = 4;
  double pi = 3.14159;
  int *pn = &n;
  double *ppi = &pi;

  ppi = (double *)pn;

  // printf("%.4f\n\n\n%d", *ppi, *pn);

  int x ;
  int y;

  printf("%d %d %d\n", x, y, test_pointer(&x, &y, 9));

  return 0;
}


int test_pointer(int *x, int *y, int z)
{
  (*x)++;
  (*y) += 10;

  return *x + *y + z;
}
