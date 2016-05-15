#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encode.h"

int main()
{
  /*test priority queue*/
  tree_node* p = NULL;
  tree_node* lc, *rc;
  float freq[] = {0.01, 0.04, 0.05, 0.11, 0.19, 0.20, 0.4};
	int NCHAR = 7; /*number of characters*/
  int i = 0;
	const char *CODE_FILE = "code.txt";
	const char *OUT_FILE = "encoded.txt";
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

	qhead = NULL;
  /*initialize with freq*/
  for(i = 0; i < NCHAR; i++) {
    insert_into_priority_queue(allocate_new_node('a'+i, freq[i]));
  }

  /*build tree*/
  for(i = 0; i < NCHAR - 1; i++) {
    lc = pop_priority_queue();
    rc = pop_priority_queue();
    /*create parent*/
    p = allocate_new_node(0,lc->freq+rc->freq);
    /*set parent link*/
    lc->parent = rc->parent = p;
    /*set child link*/
    p->right = rc; p->left = lc;
		/*make it non-leaf*/
		p->isleaf = 0;
    /*add the new node to the queue*/
    insert_into_priority_queue(p);
  }

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
	fclose(fout);
	getchar();
	/*TODO: clear resources*/
  return 0;
}
