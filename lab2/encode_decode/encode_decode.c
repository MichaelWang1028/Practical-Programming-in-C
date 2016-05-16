#include "encode_decode.h"

void get_frequency_from_file(FILE* file_name)
{
  char c;
  unsigned long long total = 0;

  while ((c = getc(file_name)) != EOF) {
    frequencies[(unsigned char) c]++;
    total++;
  }

  for (int i = 0; i < MAX_SYMBOLS; i++) {
    if (frequencies[i] > 0) {
      frequencies[i] /= total;
    }
  }
}
