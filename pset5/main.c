#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_finding_message(node* head, int value);

int main()
{
  node* head = create_node(9);
  add_node(head, 10);
  add_node(head, 21);
  add_node(head, 12);
  add_node(head, 36);

  display(head);

  print_finding_message(head, 12);
  print_finding_message(head, 5);

  puts("Testing deletion");
  puts("===================================");
  puts("Testing linear linked list");
  node* another_head = create_node(1);
  add_node(another_head, 2);
  add_node(another_head, 3);
  add_node(another_head, 4);
  add_node(another_head, 5);

  puts("Before deleting");
  display(another_head);
  another_head = delete_node(another_head, find_node(another_head, 4));
  puts("After deleting");
  display(another_head);
  puts("===================================");
  puts("Testing circlar linked list");
  node * circular_head = create_node(1);
  add_node(circular_head, 2);
  add_node(circular_head, 3);
  add_node(circular_head, 4);
  add_node(circular_head, 5);
  node* pointing_to_head = find_node(circular_head, 5);
  pointing_to_head->next = circular_head;
  puts("Before deleting");
  display(circular_head);
  circular_head = delete_node(circular_head, find_node(circular_head, 5));
  puts("After deleting");
  display(circular_head);
  circular_head = delete_node(circular_head, find_node(circular_head, 5));
  puts("After deleting");
  display(circular_head);
  puts("===================================");

  puts("Testing free");
  free_list(head);
  display(head);
  free_list(another_head);
  display(another_head);
  free_list(circular_head);
  display(circular_head);

  return 0;
}


void print_finding_message(node* head, int value)
{
  node * found = find_node(head, value);

  if (found != NULL) {
    printf("Value %d was found.\n", found->data);
  } else {
    printf("Value was not found.\n");
  }
}
