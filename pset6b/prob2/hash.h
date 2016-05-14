#ifndef HASH_H
#define HASH_H

#define MAX_BUCKETS 1000
#define MULTIPLIER 31
#define MAX_LEN 100

typedef struct wordrec
{
  char* word;
  unsigned long count;
  struct wordrec* next;
} wordrec;

#endif
