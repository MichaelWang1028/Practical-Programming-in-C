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

/* delete node and all its children
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(trie_node * pnode) {
	/* TODO: delete node and all its children
	   Be sure to free non-null translations!
	   Hint: use recursion
	 */
	 for (int i = 0; i < UCHAR_MAX + 1; i++) {
		 if (pnode->children[i] != NULL) {
			 delete_node(pnode->children[i]);
		 }
	 }
	 free(pnode);
}
