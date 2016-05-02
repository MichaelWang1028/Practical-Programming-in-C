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
