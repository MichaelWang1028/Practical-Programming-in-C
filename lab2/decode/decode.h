#ifndef DECODE_H
#define DECODE_H

#define MAX_SYMBOLS 255
#define MAX_LEN     10
#define IN_FILE "encoded.txt"
#define CODE_FILE "code.txt"
#define OUT_FILE "decoded.txt"
#define RIGHT '1'

typedef struct tree_node
{
    struct  tree_node* left; /*used when in tree*/
    struct  tree_node* right; /*used when in tree*/
    int     isleaf;
    char     symbol;
} tree_node;

typedef struct code
{
	int		symbol;
	char	str_code[MAX_LEN];
} code;

extern tree_node* root; /*tree of symbols*/

tree_node* allocate_new_tree_node();

/*
    @function build_tree
    @desc     builds the symbol tree given the list of symbols and code.h
	NOTE: alters the global variable root that has already been allocated in main
*/
void build_tree(FILE* fp);

void decode(FILE* fin, FILE* fout);

void free_tree(tree_node* root);

#endif
