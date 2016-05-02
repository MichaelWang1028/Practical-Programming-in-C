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
