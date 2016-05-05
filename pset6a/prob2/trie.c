#include <stdlib.h>
#include "trie.h"

/* allocate new node on the heap, and
	 initialize all fields to default values
   output: pointer to new node (must be freed) */
trie_node * new_node(void) {
	trie_node * p_node = (trie_node *) malloc(sizeof(trie_node));

	if (p_node != NULL) {
		p_node->translation = NULL;
		for (int i = 0; i < UCHAR_MAX + 1; i++) {
			p_node->children[i] = NULL;
		}
	}

	return p_node;
}

/* using recursion delete node and all its children
	 it also deletes all non-null translations.
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(trie_node * pnode) {
	if (pnode->translation != NULL) {
		free(pnode->translation);
	}

	for (int i = 0; i < UCHAR_MAX + 1; i++) {
		if (pnode->children[i] != NULL) {
			delete_node(pnode->children[i]);
		}
	}

	free(pnode);
}
