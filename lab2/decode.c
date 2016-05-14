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
    @desc     builds the symbol tree given the list of symbols and code.h
	NOTE: alters the global variable root that has already been allocated in main
*/
void build_tree(FILE* fp)
{
	char	symbol;
	char	str_code[MAX_LEN];
	int		items_read;
	int		i,len;
	struct	tree_node* curr = NULL;

	while(!feof(fp))
	{
		items_read = fscanf(fp, "%c %s\n", &symbol, str_code);
		if(items_read != 2) break;
		curr = root;
		len = strlen(str_code);
		for(i = 0; i < len; i++)
		{
			/*TODO: create the tree as you go*/
		}
		/*assign code*/
		curr->isleaf = 1;
		curr->symbol = symbol;
		printf("inserted symbol:%c\n", symbol);
	}
}

/*
	function decode
*/
void decode(FILE* fin, FILE* fout)
{
	char c;
	tree_node* curr = root;
	while((c = getc(fin)) != EOF)
	{
		/*TODO:
			traverse the tree
			print the symbols only if you encounter a leaf node
		*/
	}
}
/*
	@function freetree
	@desc	  cleans up resources for tree
*/

void freetree(tree_node* root)
{
	if(root == NULL)
		return;
	freetree(root->right);
	freetree(root->left);
	free(root);
}

int main()
{
	const char* IN_FILE = "encoded.txt";
	const char* CODE_FILE = "code.txt";
	const char* OUT_FILE = "decoded.txt";
	FILE* fout;
	FILE* fin;
	/*allocate root*/
	root = allocate_new_tree_node();
	fin = fopen(CODE_FILE, "r");
	/*build tree*/
	build_tree(fin);
	fclose(fin);

	/*decode*/
	fin = fopen(IN_FILE, "r");
	fout = fopen(OUT_FILE, "w");
	decode(fin, fout);
	fclose(fin);
	fclose(fout);
	/*cleanup*/
	freetree(root);
	getchar();
	return 0;
}
