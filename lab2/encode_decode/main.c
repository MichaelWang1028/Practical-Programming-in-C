#include <stdio.h>
#include "encode_decode.h"

float frequencies[MAX_SYMBOLS];

int main()
{
  FILE* input_file = fopen(INPUT_FILE, READ_MODE);
  FILE* code_file = fopen(CODE_FILE, WRITE_MODE);
  get_frequency_from_file(input_file);

  queue_head = NULL;

  initialize_priority_queue(MAX_LEN, 0, frequencies);
  display_tree_node_list(queue_head);
  build_tree(count_elements(frequencies));

  root = pop_priority_queue();
  generate_code(root, 0);
  puts("Code was generated");
  dump_code(code_file);

  return 0;
}
