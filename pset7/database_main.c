#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "prob1.h"

#define INPUT_MAX_LENGTH 2048

int initialize_db(const char * filename)
{
  const char sql[] = "SELECT * FROM movies";
  sqlite3 * database = NULL;

  if (sqlite3_open(filename, &database)){
		return 1;
	}

  char * error_message = NULL;

  ptreeroot = allocate_b_tree_node();
	sqlite3_exec(database, sql, store_result, NULL, &error_message);

  if (error_message) {
    return 2;
  }

  sqlite3_close(database);
  return 0;
}

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
  nodevalue * found_movie = NULL;

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
			break;

		found_movie = find_value(input);

    if (found_movie)
      display_record(found_movie, stdout);
    else
      puts("Movie not in database");

	} while (1);


	return 0;
}
