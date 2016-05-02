#include <stdio.h>
#include "stack.h"

int main()
{
  push(1);
  push(2);
  push(3);
  push(5);

  for (int i = 0; i < i_top; i++) {
    printf("%d\t", stack_buffer[i]);
  }
  puts("");

  return 0;
}
