#ifndef TRIE_H
#define TRIE_H

#include <limits.h>

/* the trie node data structure */
typedef struct s_trie_node
{
	char * translation; /* NULL if node not a word */

	/* pointer array to child nodes */
	struct s_trie_node * children[UCHAR_MAX + 1];
} trie_node;

/* allocate new node on the heap
   output: pointer to new node (must be freed) */
trie_node * new_node(void);

/* delete node and all its children
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(trie_node * pnode);

/* add word to trie, with translation
   input: word and translation
   output: non-zero if new node added, zero otherwise
   postcondition: word exists in trie */
int add_word(const char * word, char * translation);

#endif
