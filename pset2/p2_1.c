#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_size(char *format, int size, int min, int max);

int main()
{

  printf("Size\t\t\tMin\t\t\tMax\n");
  print_size("%4lu\t%d\t%20llu\n", sizeof(char), CHAR_MIN, CHAR_MAX);
  print_size("%4lu\t%d\t%20llu\n", sizeof(unsigned char), 0, UCHAR_MAX);
  print_size("%4lu\t%d\t%20llu\n", sizeof(short), SHRT_MIN, SHRT_MAX);
  print_size("%4lu\t%20llu\t%20llu\n", sizeof(int), INT_MIN, INT_MAX);
  print_size("%4lu\t%20llu\t%20llu\n", sizeof(unsigned int), 0, UINT_MAX);
  print_size("%4lu\t%20llu\t%20llu\n", sizeof(unsigned long), 0, ULONG_MAX);
  print_size("%4lu\t%20f\t%20Lf\n", sizeof(float), FLT_MIN, FLT_MAX);

  return 0;
}

void print_size(char *format, int size, int min, int max)
{
  printf(format, size, min, max);
}
