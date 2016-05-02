#include <stdio.h>
#include "stack.h"

int stack_buffer[100];
int i_top = 0;

void push(int elem)
{
  stack_buffer[i_top++] = elem;
}

int pop()
{
  if (i_top > 0) {
    return stack_buffer[--i_top];
  } else {
    return -1;
  }
}


void print_stack()
{
  for (int i = 0; i < i_top; i++) {
    printf("%d\t", stack_buffer[i]);
  }
  puts("");
}
