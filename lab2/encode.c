#include <stdio.h>
#include <stdlib.h>
#include "encode.h"

char code[MAX_SYMBOLS][MAX_LEN];
tree_node* root = NULL; /*tree of symbols*/
tree_node* qhead = NULL; /*list of current symbols*/
struct cnode* chead = NULL;/*list of code*/

tree_node* allocate_new_node(int symbol, float freq)
{
  tree_node* p = (tree_node *) malloc(sizeof(tree_node));

  if (p != NULL)
  {
    p->left = p->right = p->parent = p->next = NULL;
    p->symbol = symbol;
    p->freq = freq;
    p->isleaf = 1;
  }

  return p;
}

void display_tree_node_list(tree_node* head)
{
  tree_node* p = NULL;
  printf("list:");

  for(p = head; p != NULL; p = p->next) {
    printf("(%c,%f) ", p->symbol, p->freq);
  }

  printf("\n");
}

/*
  NOTE: makes use of global variable qhead
*/
void insert_into_priority_queue(tree_node* p)
{
  tree_node* curr = NULL;
  tree_node* prev = NULL;
  printf("inserting:%c,%f\n", p->symbol, p->freq);

  if (qhead == NULL) {/*qhead is null*/
    /*TODO: write code to insert when queue is empty*/
  }
  /*TODO: write code to find correct position to insert*/
  if (curr == qhead) {
    /*TODO: write code to insert before the current start*/
  } else { /*insert between prev and next*/
    /*TODO: write code to insert in between*/
  }
}

/*
  @function pop_priority_queue
  @desc     removes the first element
  NOTE:     makes use of global variable qhead
*/
tree_node* pop_priority_queue()
{
  tree_node* p = NULL;
  /*TODO: write code to remove front of the queue*/
	printf("popped:%c,%f\n", p->symbol, p->freq);
  return p;
}

/*
	@function build_code
	@desc     generates the string codes given the tree
	NOTE: makes use of the global variable root
*/
void generate_code(tree_node* root, int depth)
{
	int symbol;
	int len; /*length of code*/
	if (root->isleaf) {
		symbol = root->symbol;
		len = depth;
		/*start backwards*/
		code[symbol][len] = 0;
		/*
			TODO: follow parent pointer to the top
			to generate the code string
		*/
		printf("built code:%c,%s\n", symbol, code[symbol]);
	} else {
		generate_code(root->left, depth + 1);
		generate_code(root->right, depth + 1);
	}
}

/*
	@func	dump_code
	@desc	output code file
*/
void dump_code(FILE* fp)
{
	for(int i = 0; i < MAX_SYMBOLS; i++) {
		if (code[i][0]) /*non empty*/
			fprintf(fp,"%c %s\n", i, code[i]);
	}
}

/*
	@func	encode
	@desc	outputs compressed stream
*/
void encode(char* str, FILE* fout)
{
  while (*str) {
		fprintf(fout, "%s", code[*str]);
		str++;
	}
}
