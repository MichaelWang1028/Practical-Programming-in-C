#ifndef ENCODE_DECODE_H
#define ENCODE_DECODE_H

#include <stdio.h>
#include "../encode/encode.h"

#define READ_MODE "r"
#define WRITE_MODE "w"
#define APPEND_MODE "a"
#define INPUT_FILE "book.txt"

extern float frequencies[MAX_SYMBOLS];

void get_frequency_from_file(FILE* file_name);
int count_elements(float frequencies[]);

#endif
