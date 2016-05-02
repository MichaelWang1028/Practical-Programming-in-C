#include <stdio.h>
#include "stack.h"

int main()
{
  push(1);
  push(2);
  push(3);
  push(5);

  print_stack();
  pop();
  pop();
  print_stack();

  printf("%d\n", top());
  print_stack();

  return 0;
}
