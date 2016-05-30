#include <stdio.h>
#include "queue_array.h"

int queue_buffer[NUMBER_OF_ELEMENTS];
int i_front = 0;
int i_count = 0;

void enqueue(double element)
{
  if (i_count < NUMBER_OF_ELEMENTS) {
    queue_buffer[(i_front + i_count) % NUMBER_OF_ELEMENTS] = element;
    i_count++;
  }
}

int dequeue()
{
  if (i_count > 0) {
    int element = queue_buffer[i_front];
    i_count--;
    i_front++;

    if (i_front == NUMBER_OF_ELEMENTS) {
      i_front = 0;
    }

    return element;
  }
  return -1;
}

void print_queue()
{
  for (int i = i_front; i <  i_count + i_front; i++) {
    printf("%d\t", queue_buffer[i % NUMBER_OF_ELEMENTS]);
  }
  puts("");
}
