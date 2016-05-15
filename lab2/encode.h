#ifndef ENCODE_H
#define ENCODE_H

#define MAX_SYMBOLS 255
#define MAX_LEN     7

typedef struct tree_node
{
    struct  tree_node* left; /*used when in tree*/
    struct  tree_node* right; /*used when in tree*/
    struct  tree_node* parent;/*used when in tree*/
    struct  tree_node* next; /*used when in list*/
    float   freq;
    int     isleaf;
    char    symbol;
} tree_node;

extern char code[MAX_SYMBOLS][MAX_LEN];
extern tree_node* root; /*tree of symbols*/
extern tree_node* qhead; /*list of current symbols*/
extern struct cnode* chead;/*list of code*/

tree_node* allocate_new_node(int symbol, float freq);

#endif
