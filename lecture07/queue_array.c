#include "queue_array.h"

int queue_buffer[100];
int i_front = 0;
int i_count = 0;

void enqueue(double element)
{
  if (i_count < NUMBER_OF_ELEMENTS) {
    queue_buffer[i_front + i_count] = element;
    i_count++;
  }
}

int dequeue()
{
  if (i_count > 0) {
    i_count--;
    return queue_buffer[i_front++];
  }
  return -1;
}
