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

/* static variables for the root of the tree and number of records */
extern p_tnode ptreeroot;
extern unsigned int record_count;

/* allocate_record() - allocate a new record on the heap */
struct s_record * allocate_record();

/* free_record() - frees the record structure and associated strings */
void free_record(struct s_record * precord);

/* display_record -- output record information to file pointer fp */
void display_record(struct s_record * precord, FILE * fp);

/* allocate_b_tree_node() - creates a new B-tree node on the heap */
p_tnode allocate_b_tree_node(void);

/* free_tnode() - frees a node in the B-tree,
 * its associated record, and all its children from memory
 */
void free_tnode(p_tnode pnode);

/* function for comparing two keys; simply calls the case-insensitive
 * string comparison function strcasecmp() declared in string.h.
 * Returns zero if both equal, positive if key1 > key2, negative if key1 < key2
 */
int key_compare(const nodekey key1, const nodekey key2);


int find_index(nodekey key, p_tnode pnode);

/* split_node() - splits a full node in the B-tree into two separate nodes,
 * possibly creating a new root node in the process
 * should be no need to modify this function
 */
void split_node(p_tnode * ppnode, int * poffset);

/* add_element() - add the record with the specified key to the B-tree.
 * returns a pointer to an already existing record with the same key,
 * in which case, the new record was not inserted, or NULL on success
 * should be no need to modify this function
 */
nodevalue * add_element(nodekey key, nodevalue * pvalue);

void inorder_traversal(p_tnode pnode, FILE * fp);

nodevalue * find_value(const nodekey key); // TODO

/* display_result() - print information from the database
 * this function is a valid callback for use with sqlite3_exec()
 * pextra is unused
 *
 * needs to return zero (nonzero aborts SQL query)
 */
int display_result(void * pextra, int nfields, char ** arrvalues, char ** arrfieldnames);

/* store_result() - store record from database in B-tree
 * this function is also a valid callback for use with sqlite3_exec()
 * pextra is again unused
 *
 * needs to return zero (nonzero aborts SQL query)
 */
int store_result(void * pextra, int nfields, char ** arrvalues, char ** arrfieldnames);

int initialize_db(const char * filename);

#endif
