#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

typedef struct stack_node {
  int element;
  struct stack_node * next_node;
} stack_node;

extern stack_node * stack_buffer;

void push(int element);
int pop();
void print_stack();

#endif
