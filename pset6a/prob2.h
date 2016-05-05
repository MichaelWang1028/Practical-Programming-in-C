#ifndef PROB2_H
#define PROB2_H

/* maximum number of characters for word to search */
#define WORD_MAX 256

/* maximum number of characters in line */
#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

/* pointer to the root node of the trie structure */
extern struct s_trie_node * proot;

/* read dictionary file into trie structure */
unsigned int load_dictionary(const char * filename);

/* search trie structure for word and return translations
   input: word to search
   output: translation, or NULL if not found */
char * lookup_word(const char * word);

#endif
