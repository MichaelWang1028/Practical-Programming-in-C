#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

typedef struct queue_node {
  int element;
  struct queue_node * next_node;
} queue_node;

extern queue_node * queue_buffer;
extern queue_node * rear_node;

#endif
