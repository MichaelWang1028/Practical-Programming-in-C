#ifndef TRIE_H
#define TRIE_H

/* the trie node data structure */
struct s_trie_node
{
	char * translation; /* NULL if node not a word */

	/* pointer array to child nodes */
	struct s_trie_node * children[UCHAR_MAX + 1];
};

#endif
