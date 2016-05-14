#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"

struct tree_node
{
    struct  tree_node* left; /*used when in tree*/
    struct  tree_node*right; /*used when in tree*/
    int     isleaf;
    char     symbol;
};

struct code
{
	int		symbol;
	char	strcode[MAX_LEN];
};

/*global variables*/
struct tree_node* root = NULL; /*tree of symbols*/

/*
    @function   talloc
    @desc       allocates new node
*/
struct tree_node* talloc()
{
    struct tree_node* p = (struct tree_node *) malloc(sizeof(struct tree_node));
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
	char	strcode[MAX_LEN];
	int		items_read;
	int		i,len;
	struct	tree_node* curr = NULL;

	while(!feof(fp))
	{
		items_read = fscanf(fp, "%c %s\n", &symbol, strcode);
		if(items_read != 2) break;
		curr = root;
		len = strlen(strcode);
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
	struct tree_node* curr = root;
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

void freetree(struct tree_node* root)
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
	root = talloc();
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
