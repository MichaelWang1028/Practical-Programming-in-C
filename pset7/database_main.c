#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "prob1.h"

#define INPUT_MAX_LENGTH 2048

int main(int argc, char * argv[]) {

	/* part (a): execute the first three SQL queries */
	// const char sql[] = "SELECT * FROM movies WHERE ProductionYear < 1950";
	// const char sql[] = "SELECT * FROM movies WHERE Format == \"VHS\"";
	// const char sql[] = "SELECT * FROM movies WHERE Language == \"Spanish\"";

	if (argc < 2) {
		fprintf(stderr,"Error: database name not specified!\n");
		return 1;
	}

	char * database_name = argv[1];
  int error = initialize_db(database_name);

  if (error == 0) {
    puts("Database loaded successfully on b-tree.");
  } else {
    puts("Error: database was not loaded!");
    return error;
  }

  char input[INPUT_MAX_LENGTH];
  unsigned int len;

  dump_sorted_list("output.txt");

  do {
		printf("Enter a movie title: ");
		fflush(stdout);
		if (!fgets(input, INPUT_MAX_LENGTH, stdin))
			abort(); /* failed to read stdin */

		len = strlen(input);
		/* remove trailing newline character */
		if (len > 0 && input[len-1] == '\n') {
			input[len-1] = '\0';
			--len;
		}

		if (len == 0) /* empty expression signals exit */
    {
      break;
    }

    locate_movie(input);

	} while (1);

  cleanup();

	return 0;
}
