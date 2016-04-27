#include <stdlib.h>
#include "binary_tree.h"


tree_node* allocate_tree_node(int data)
{
  tree_node* new_tree_node = (tree_node *) malloc(sizeof(tree_node));

  if (new_tree_node != NULL) {
    new_tree_node->data = data;
    new_tree_node->left = NULL;
    new_tree_node->right = NULL;
  }

  return new_tree_node;
}

tree_node* add_tree_node(tree_node* root, int data)
{
  if (root == NULL) {
    return allocate_tree_node(data);
  } else if (data < root->data) {
    root->left = add_tree_node(root->left, data);
  } else {
    root->right = add_tree_node(root->right, data);
  }
  return root;
}

void display_pre_order_traversal(tree_node* root)
{
  
}
