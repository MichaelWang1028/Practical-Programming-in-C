#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node
{
  int data;
  struct node * next;
} node;

node * create_node(int data);
node * add_node_at_front(node * head, int data);
node * add_node(node * head, int data);
node * find_node(node * head, int data);
node * delete_node(node * head, node * pointing_element);
void free_list(node * head);
void display(node * head);

#endif
