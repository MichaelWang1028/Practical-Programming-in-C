#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prob2.h"
#include "trie.h"

int main(int argc, char * argv[]) {
	char word[WORD_MAX], * translation;
	int len;

	if (argc <= 1)
		return 0; /* no dictionary specified */

	/* load dictionary */
	proot = new_node();
	load_dictionary(argv[1]);

	do {
		printf("Enter word to translate: ");
		fflush(stdout);
		if (!fgets(word, WORD_MAX, stdin))
			abort();

		/* strip trailing newline */
		len = strlen(word);
		if (len > 0 && word[len-1] == '\n') {
			word[len-1] = '\0';
			--len;
		}

		/* exit on empty string */
		if (len == 0)
			break;

		/* lookup word */
		translation = lookup_word(word);

		if (translation)
			printf("%s -> %s\n", word, translation);
		else
			printf("\"%s\" not found\n", word);
	} while (1);

	/* clean up trie structure */
	delete_node(proot);

	return 0;
}
