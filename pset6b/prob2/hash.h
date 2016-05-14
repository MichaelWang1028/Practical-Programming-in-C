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

/*
   @function walloc
   @desc     produces a new node
 */
wordrec* walloc(const char* str);

/*
   @function hashstring
   @desc     produces hash code for a string
            multipliers 31,35 have been found to work well
 */
unsigned long hashstring(const char* str);

/*
   @function lookup
   @desc     returns a pointer to the word or creates
            it if required
 */
wordrec* lookup(const char* str, int create);

/*
   @function cleartable()
   @desc     reclaims memory
 */
void cleartable();

#endif
