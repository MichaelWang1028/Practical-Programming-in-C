#include <stdio.h>
#include "encode_decode.h"

float frequencies[MAX_SYMBOLS];
void encode_file(FILE* file_name);

int main()
{
  FILE* input_file = fopen(INPUT_FILE, READ_MODE);
  FILE* code_file = fopen(CODE_FILE, WRITE_MODE);
  get_frequency_from_file(input_file);
  fclose(input_file);
  input_file = fopen(INPUT_FILE, READ_MODE);

  queue_head = NULL;

  initialize_priority_queue(MAX_LEN, 0, frequencies);
  // display_tree_node_list(queue_head);
  build_tree(count_elements(frequencies));

  root = pop_priority_queue();
  generate_code(root, 0);
  dump_code(code_file);
  free_tree(root);

  encode_file(input_file);
  // puts("after encoding file");

  fclose(code_file);

  return 0;
}

void encode_file(FILE* file_name)
{
  FILE* encoded_file = fopen(OUT_FILE, WRITE_MODE);
  char c;
  while ((c = getc(file_name)) != EOF) {
    char string[] = {(unsigned char) c, '\0'};
    // printf("%d\t%c\n", c, c);

    encode(string, encoded_file);
  }
  fprintf(encoded_file, "\n");
  fclose(encoded_file);
}
