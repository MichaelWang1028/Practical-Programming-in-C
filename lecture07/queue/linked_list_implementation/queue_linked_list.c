#include <stdio.h>
#include <stdlib.h>
#include "queue_linked_list.h"

queue_node * queue_buffer = NULL;
queue_node * rear_node = NULL;

void enqueue(int element)
{
  queue_node * new_node = (queue_node *) malloc(sizeof(queue_node));

  if (new_node != NULL) {
    new_node->element = element;
    new_node->next_node = NULL;

    if (rear_node != NULL) {
      rear_node->next_node = new_node;
    } else {
      queue_buffer = new_node;
    }
    rear_node = new_node;
  }
}

int dequeue()
{
  if (queue_buffer != NULL) {
    queue_node * temp_node = queue_buffer;
    int element = queue_buffer->element;
    queue_buffer = queue_buffer->next_node;

    if (temp_node == rear_node) {
      rear_node = NULL;
    }
    free(temp_node);
    return element;
  } else {
    return -1;
  }
}

void print_queue()
{
  for (queue_node *  node = queue_buffer; node != NULL; node = node->next_node) {
    printf("%d\t", node->element);
  }
  puts("");
}
