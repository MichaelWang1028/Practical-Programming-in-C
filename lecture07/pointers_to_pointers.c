#include <stdio.h>

int main()
{
  int n = 9;
  int * pn = &n;
  int ** ppn = &pn;

  printf("This is n: %d\n", n);
  printf("This is pn: %p\n", pn);
  printf("This is *pn: %d the same as n\n", *pn);
  printf("This is ppn: %p\n", ppn);
  printf("This is *ppn: %p the same as pn.\n", *ppn);
  printf("This is **ppn: %d the same as *pn and n.\n", **ppn);

  return 0;
}
