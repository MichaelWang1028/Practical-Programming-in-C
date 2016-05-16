#ifndef ENCODE_H
#define ENCODE_H

#include <stdio.h>

#define MAX_SYMBOLS 255
#define MAX_LEN     255
#define CODE_FILE "code.txt"
#define OUT_FILE "encoded.txt"

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
extern tree_node* queue_head; /*list of current symbols*/
extern struct cnode* chead;/*list of code*/

tree_node* allocate_new_node(int symbol, float freq);

void display_tree_node_list(tree_node* head);

void insert_into_priority_queue(tree_node* p);

/*
    @function pop_priority_queue
    @desc     removes the first element
    NOTE:     makes use of global variable qhead
*/
tree_node* pop_priority_queue();

/*
	@function build_code
	@desc     generates the string codes given the tree
	NOTE: makes use of the global variable root
*/
void generate_code(tree_node* root,int depth);

/*
	@func	dump_code
	@desc	output code file
*/
void dump_code(FILE* fp);

/*
	@func	encode
	@desc	outputs compressed stream
*/
void encode(char* str, FILE* fout);

void free_tree(tree_node* root);

void initialize_priority_queue(int characters, char initial_char, float frequencies[]);

void build_tree(int characters);
#endif
