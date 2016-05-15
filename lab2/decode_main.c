#include <stdio.h>
#include "decode.h"

int main()
{
	FILE* output_file;
	FILE* input_file;
	/*allocate root*/
	root = allocate_new_tree_node();
	input_file = fopen(CODE_FILE, "r");
	/*build tree*/
	build_tree(input_file);
	fclose(input_file);

	/*decode*/
	input_file = fopen(IN_FILE, "r");
	output_file = fopen(OUT_FILE, "w");
	decode(input_file, output_file);
	fclose(input_file);
	fclose(output_file);
	/*cleanup*/
	free_tree(root);
	getchar();
	return 0;
}
