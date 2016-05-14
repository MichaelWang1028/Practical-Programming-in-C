#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

/*hash bucket*/
wordrec* table[MAX_BUCKETS]; /* changed from MAX_LEN -- dsw */

/*
  @function walloc
  @desc     produces a new node
*/
wordrec* walloc(const char* str)
{
  wordrec* p = (wordrec *) malloc(sizeof(wordrec));
  if(p != NULL)
  {
      p->count = 0;
      p->word = strdup(str); /*creates a duplicate*/
      p->next = NULL;
  }
  return p;
}

/*
  @function hashstring
  @desc     produces hash code for a string
            multipliers 31,35 have been found to work well
*/
unsigned long hashstring(const char* str)
{
  unsigned long hash = 0;
  while(*str)
    {
      hash = hash * MULTIPLIER + *str;
      str++;
    }
  return hash % MAX_BUCKETS;
}


/*
  @function lookup
  @desc     returns a pointer to the word or creates
            it if required
*/
wordrec* lookup(const char* str, int create)
{
  unsigned long hash = hashstring(str);/*starting point*/
  wordrec *wp = table[hash];
  wordrec *curr = NULL;

  for (curr = wp; curr != NULL; curr = curr->next) {
    if (strcmp(curr->word, str) == 0) {
      return curr;
    }
  }

  /*if not found and create specified*/
  if (create)
  {
    curr = walloc(str);
    curr->next = wp;
    table[hash] = curr;
  }

  return curr;
}

/*
  @function cleartable()
  @desc     reclaims memory
*/
void cleartable()
{
  wordrec* wp = NULL,*p = NULL;

  for (int i = 0; i < MAX_BUCKETS; i++) {
    wp = table[i];
    for (p = wp; p != NULL; p = wp) {
        wp = p->next;
        free(p->word);
        free(p);
    }
  }
}
