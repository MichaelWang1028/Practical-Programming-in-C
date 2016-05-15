#include <stdio.h>
#include "decode.h"

int main()
{
	FILE* output_file;
	FILE* input_file;

	root = allocate_new_tree_node();
	input_file = fopen(CODE_FILE, "r");

	build_tree(input_file);
	fclose(input_file);


	input_file = fopen(IN_FILE, "r");
	output_file = fopen(OUT_FILE, "w");
	decode(input_file, output_file);
	fclose(input_file);
	fclose(output_file);

	free_tree(root);
	getchar();
	return 0;
}
