#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"

tree_node* root = NULL; /*tree of symbols*/

tree_node* allocate_new_tree_node()
{
    tree_node* p = (tree_node *) malloc(sizeof(tree_node));

    if(p != NULL)
    {
      p->left = p->right = NULL;
      p->symbol = 0;
      p->isleaf = 0;
    }
    return p;
}

/*
    @function build_tree
    @desc     builds the symbol tree given the list of symbols and code.txt
	NOTE: alters the global variable root that has already been allocated in main
*/
void build_tree(FILE* fp)
{
	char	symbol;
	char	str_code[MAX_LEN];
	int		items_read;
	int		i, len;
	struct	tree_node* curr = NULL;

	while(!feof(fp))
	{
		items_read = fscanf(fp, "%c %s\n", &symbol, str_code);

		if (items_read != 2) {
      break;
    }

		curr = root;
		len = strlen(str_code);
		for(i = 0; i < len; i++)
		{
      if (str_code[i] == RIGHT) {
        if (curr->right == NULL)
          curr->right = allocate_new_tree_node();
      } else {
        if (curr->left == NULL)
          curr->left = allocate_new_tree_node();
      }
      curr = (str_code[i] == RIGHT) ? curr->right : curr->left;
		}

		/*assign code*/
		curr->isleaf = 1;
		curr->symbol = symbol;
		printf("inserted symbol: %c\n", symbol);
	}
}

void decode(FILE* input_file, FILE* output_file)
{
	char c;
	tree_node* curr = root;
	while((c = getc(input_file)) != EOF)
	{
    if (curr->isleaf) {
      fprintf(output_file, "%c", curr->symbol);
      curr = root;
    }

    curr = (c == RIGHT) ? curr->right : curr->left;
	}
  fprintf(output_file, "\n");
}

void free_tree(tree_node* root)
{
	if(root == NULL) {
    return;
  }

	free_tree(root->right);
	free_tree(root->left);
	free(root);
}
