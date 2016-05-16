#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"

int main()
{
  /*test priority queue*/
  tree_node* p = NULL;
  float freq[] = {0.01, 0.04, 0.05, 0.11, 0.19, 0.20, 0.4};
	int NCHAR = 7; /*number of characters*/

	FILE* fout = NULL;
	/*zero out code*/
	memset(code, 0, sizeof(code));

	/*testing queue*/
  insert_into_priority_queue(allocate_new_node('a', 0.1));
  insert_into_priority_queue(allocate_new_node('b', 0.2));
  insert_into_priority_queue(allocate_new_node('c', 0.15));
  /*making sure it pops in the right order*/
	puts("making sure it pops in the right order");
	while ((p = pop_priority_queue())) {
    free(p);
  }

	queue_head = NULL;
  /*initialize with freq*/
  initialize_priority_queue(NCHAR, 'a', freq);

  display_tree_node_list(queue_head);

  /*build tree*/
  build_tree(NCHAR);

  /*get root*/
  root = pop_priority_queue();
	/*build code*/
	generate_code(root, 0);
	/*output code*/
	puts("code:");
	fout = fopen(CODE_FILE, "w");
	dump_code(stdout);
	dump_code(fout);
	fclose(fout);

	/*encode a sample string*/
	puts("orginal:abba cafe bad");
	fout = fopen(OUT_FILE,"w");
	encode("abba cafe bad", stdout);
	encode("abba cafe bad", fout);
  fprintf(fout, "\n");
	fclose(fout);
	getchar();

  free_tree(root);

  return 0;
}
