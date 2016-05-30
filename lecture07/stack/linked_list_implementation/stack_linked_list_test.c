#include <stdio.h>
#include "stack_linked_list.h"

int main()
{
  push(1);
  push(2);
  push(3);
  push(5);

  print_stack();
  pop();
  print_stack();
  pop();
  print_stack();
  printf("%d\n", top());
  print_stack();

  return 0;
}
