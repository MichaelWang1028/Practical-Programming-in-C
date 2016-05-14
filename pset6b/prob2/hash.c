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
  /*TODO: write code to
  follow the linked list to find str
  if found return pointer*/

  /*if not found and create specified*/
   if(create)
    {
      /*TODO:write code to
       create new node
      update linked list*/
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
  int i = 0;
  /*TODO: write code to
    reclaim memory
  */
}
