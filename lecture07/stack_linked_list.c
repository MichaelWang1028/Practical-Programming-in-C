#include <stdio.h>
#include <stdlib.h>
#include "stack_linked_list.h"

stack_node * stack_buffer = NULL;

void push(int element)
{
  stack_node * new_node = (stack_node *) malloc(sizeof(stack_node));

  if (new_node != NULL) {
    new_node->next_node = stack_buffer;
    new_node->element = element;
    stack_buffer = new_node;
  }
}

void print_stack()
{
  for (stack_node* s_node = stack_buffer; s_node != NULL; s_node = s_node->next_node) {
    printf("%d\t", s_node->element);
  }
  puts("");
}
