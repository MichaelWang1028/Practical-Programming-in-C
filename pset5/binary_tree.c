#include <stdio.h>
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
  if (root != NULL) {
    printf("%d\t", root->data);
  }

  if (root->left != NULL) {
    display_pre_order_traversal(root->left);
  }

  if (root->right != NULL) {
    display_pre_order_traversal(root->right);
  }
}

void display_in_order_traversal(tree_node* root)
{
  if (root->left != NULL) {
    display_in_order_traversal(root->left);
  }

  if (root != NULL) {
    printf("%d\t", root->data);
  }

  if (root->right != NULL) {
    display_in_order_traversal(root->right);
  }
}

int delete_tree(tree_node* root)
{
  static int deleted_nodes = 0;
  if (root->left != NULL) {
    delete_tree(root->left);
  }

  if (root->right != NULL) {
    delete_tree(root->right);
  }

  if (root != NULL) {
    free(root);
    deleted_nodes++;
  }

  return deleted_nodes;
}
