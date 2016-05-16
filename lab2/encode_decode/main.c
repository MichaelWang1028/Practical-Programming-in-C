#include <stdio.h>
#include "encode_decode.h"

float frequencies[MAX_SYMBOLS];

int main()
{
  FILE* code_file = fopen(CODE_FILE, WRITE_MODE);
  FILE* output_file = fopen(OUT_FILE, WRITE_MODE);
  FILE* encoded_file = fopen(ENCODED, READ_MODE);
  FILE* decoded_file = fopen(DECODED, WRITE_MODE);
  get_frequency_from_file(INPUT_FILE);

  queue_head = NULL;

  initialize_priority_queue(MAX_LEN, 0, frequencies);
  // display_tree_node_list(queue_head);
  build_tree(count_elements(frequencies));

  root = pop_priority_queue();
  generate_code(root, 0);
  dump_code(code_file);

  encode_file(INPUT_FILE);

  decode(encoded_file, decoded_file);

  free_tree(root);
  fclose(code_file);
  fclose(output_file);
  return 0;

}
