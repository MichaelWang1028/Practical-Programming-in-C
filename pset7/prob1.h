#ifndef PROB1_H
#define PROB1_H

/* T defines minimum number of children in non-root nodes
 * 2*T is maximum number of children in all nodes
 * 2*T-1 is maximum number of keys in all nodes */
#define T 3

typedef char * nodekey;

/* record structure */
typedef struct s_record {
	unsigned int irecord; /* index of record in main database */
	char * name; /* movie name used as key */
	char * category;
	unsigned int year;
	char * format;
	char * language;
	char * url;
} nodevalue;

/* B-tree node structure */
typedef struct s_tnode {
	nodekey keys[2 * T - 1]; /* keys */
	nodevalue * values[2 * T - 1]; /* values */
	unsigned int nkeys; /* number of keys, < 2 * T */

	struct s_tnode * parent; /* pointer to parent */
	struct s_tnode * children[2 * T]; /* pointers to children */
} * p_tnode;

/* allocate_record() - allocate a new record on the heap */
struct s_record * allocate_record();

#endif
