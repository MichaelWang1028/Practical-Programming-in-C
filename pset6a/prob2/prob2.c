/*
 * prob2.c
 *
 *  Created on:
 *      Author:
 */

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prob2.h"
#include "trie.h"

/* pointer to the root node of the trie structure */
trie_node * proot = NULL;

/* add word to trie, with translation
	 if word exists, translation is appended
	 to existing	string.
   input: word and translation
   output: non-zero if new node added, zero otherwise
   postcondition: word exists in trie */
int add_word(const char * word, char * translation) {
	int nodes_created = 0;
	trie_node * current_node = proot;

	for (unsigned int i = 0; i < strlen(word); i++) {
		unsigned char index = (unsigned char) word[i];
		if (current_node->children[index] == NULL) {
			current_node->children[index] = new_node();
			nodes_created++;
		}
		current_node = current_node->children[index];
	}

	/* makes sure to store a copy of translation, since
	the string is reused by load_dictionary() */
	if (current_node->translation == NULL) {
		current_node->translation = strdup(translation);
	} else {
		char * old_translation = current_node->translation;
		int old_length = strlen(old_translation);
		int new_length = strlen(translation);
		current_node->translation = malloc((old_length + new_length + 2) * sizeof(char)); // 2 = 1 (comma) + 1 (\0)
		strcpy(current_node->translation, old_translation);
		strcpy(current_node->translation + old_length, ",");
		strcpy(current_node->translation + old_length + 1, translation);
		free(old_translation);
	}

	return nodes_created;
}

/* read dictionary file into trie structure */
unsigned int load_dictionary(const char * filename) {
	FILE * pfile;
	char line[LINE_MAX], * word, * translation;
	unsigned int icount = 0;

	/* ensure file can be opened */
	if ( !(pfile = fopen(filename,"r")) )
		return icount;

	/* read lines */
	while ( (fgets(line, LINE_MAX, pfile)) ) {
		/* strip trailing newline */
		int len = strlen(line);
		if (len > 0 && line[len-1] == '\n') {
			line[len-1] = '\0';
			--len;
		}

		if (len == 0 || line[0] == '#')
			continue; /* ignore comment/empty lines */

		/* separate word and translation */
		word = line + strspn(line, DELIMS);
		if ( !word[0] )
			continue; /* no word in line */
		translation = word + strcspn(word, DELIMS);
		*translation++ = '\0';
		translation += strspn(translation, DELIMS);

		/* add word to trie */
		if (add_word(word, translation))
			icount++;
	}

	/* finish */
	fclose(pfile);
	return icount;
}

/* search trie structure for word and return translations
   input: word to search
   output: translation, or NULL if not found */
char * lookup_word(const char * word) {
	trie_node * current_node = proot;
	for (unsigned int i = 0; i < strlen(word); i++) {
		unsigned int index = (unsigned int) word[i];
		if (current_node->children[index] == NULL) {
			return NULL;
		}
		current_node = current_node->children[index];
	}

	return current_node->translation;
}
