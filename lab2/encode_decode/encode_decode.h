#ifndef ENCODE_DECODE_H
#define ENCODE_DECODE_H

#include "../encode/encode.h"

#define READ_MODE "r"
#define WRITE_MODE "w"
#define APPEND_MODE "a"
#define INPUT_FILE "book.txt"
#define RIGHT '1'
#define ENCODED "encoded.txt"
#define DECODED "decoded.txt"

extern float frequencies[MAX_SYMBOLS];

void get_frequency_from_file(char *file_name);
int count_elements(float frequencies[]);
void encode_file(char *file_name);
void decode(FILE* input_file, FILE* output_file);

#endif
