#include <stdio.h>
#include "queue_linked_list.h"

int main()
{
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(5);
  enqueue(8);
  print_queue();
  dequeue();
  dequeue();
  print_queue();
  enqueue(13);
  enqueue(21);
  print_queue();

  return 0;
}
