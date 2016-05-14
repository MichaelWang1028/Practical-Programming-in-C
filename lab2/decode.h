#ifndef DECODE_H
#define DECODE_H

#define MAX_SYMBOLS 255
#define MAX_LEN     10

typedef struct tree_node
{
    struct  tree_node* left; /*used when in tree*/
    struct  tree_node*right; /*used when in tree*/
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

#endif
