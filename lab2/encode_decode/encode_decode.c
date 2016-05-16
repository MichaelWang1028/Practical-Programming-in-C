#include <stdio.h>
#include "encode_decode.h"

void get_frequency_from_file(char *file_name)
{
  FILE* input_file = fopen(file_name, READ_MODE);
  char c;
  unsigned long long total = 0;

  while ((c = getc(input_file)) != EOF) {
    frequencies[(unsigned char) c]++;
    total++;
  }

  for (int i = 0; i < MAX_SYMBOLS; i++) {
    if (frequencies[i] > 0) {
      frequencies[i] /= total;
    }
  }

  fclose(input_file);
}

int count_elements(float frequencies[])
{
  int counter = 0;

  for (int i = 0; i < MAX_SYMBOLS; i++) {
    if (frequencies[i] > 0) {
      counter++;
    }
  }

  return counter;
}

void encode_file(char *file_name)
{
  FILE* input_file = fopen(file_name, READ_MODE);
  FILE* encoded_file = fopen(OUT_FILE, WRITE_MODE);
  char c;
  while ((c = getc(input_file)) != EOF) {
    char string[] = {(unsigned char) c, '\0'};

    encode(string, encoded_file);
  }
  fprintf(encoded_file, "\n");

  fclose(input_file);
  fclose(encoded_file);
}

void decode(FILE* input_file, FILE* output_file)
{
	char c;
	tree_node* curr = root;
	while((c = getc(input_file)) != EOF)
	{
    if (curr->isleaf) {
      fprintf(output_file, "%c", curr->symbol);
      curr = root;
    }

    curr = (c == RIGHT) ? curr->right : curr->left;
	}
}
