#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node * create_node(int data)
{
  node * new_node = (node *) malloc(sizeof(node));

  if (new_node != NULL) {
    new_node->data = data;
    new_node->next = NULL;
  }

  return new_node;
}

node* add_node_at_front(node * head, int data)
{
  node * new_head = create_node(data);

  if (new_head == NULL) {
    return head;
  }

  if (head ==  NULL) {
    return new_head;
  }

  new_head->next = head;
  return new_head;
}

node * add_node(node * head, int data)
{
  node * new_node = create_node(data);

  if (new_node == NULL) {
    return head;
  }

  if (head == NULL) {
    return new_node;
  }

  node * current_node = head;

  while(current_node->next != NULL) {
    current_node = current_node->next;
  }

  current_node->next = new_node;

  return head;
}

node * find_node(node * head, int data)
{
  for (node * current_node = head; current_node != NULL; current_node = current_node->next) {
    if (current_node->data == data) {
      return current_node;
    }
  }
  return NULL;
}

node * delete_node(node * head, node * pointing_element)
{
  node* node_to_delete = find_node(head, pointing_element->data)->next;

  if (node_to_delete == NULL) {
    return head;
  }

  pointing_element->next = node_to_delete->next;
  free(node_to_delete);

  return node_to_delete == head? pointing_element->next: head;
}

void free_list(node * head)
{
  node * current_node = head;

  while (current_node != NULL) {
    node * node_to_free = current_node;
    current_node = current_node->next;
    free(node_to_free);

    if (current_node == head) {
      break;
    }
  }
}

void display(node * head)
{
  node * p = head;

  if (p == NULL) {
    puts("Linked list is empty");
    return;
  }

  for (; p != NULL; p = p->next) {
    if (p->next == head) {
      printf("%d\t", p->data);
      puts("This is a circular linked list");
      return;
    }

    printf("%d\t", p->data);
  }

  printf("\n");
}
