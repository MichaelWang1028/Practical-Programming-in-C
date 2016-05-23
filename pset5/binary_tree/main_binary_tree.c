#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

tree_node* add_tree_nodes(tree_node* root, int nodes[], int size);

int main()
{

  int tree_nodes[] = {3, 1, 0, 2, 8, 6, 5, 9};
  tree_node* root = NULL;
  root = add_tree_nodes(root, tree_nodes, 8);

  display_pre_order_traversal(root);
  printf("\n");

  display_in_order_traversal(root);
  printf("\n");

  int deleted_nodes = delete_tree(root);

  printf("Deleted nodes: %d\n", deleted_nodes);

  return 0;
}

tree_node* add_tree_nodes(tree_node* root, int nodes[], int size)
{
  for (int i = 0; i < size; i++) {
    root = add_tree_node(root, nodes[i]);
  }
  return root;
}
