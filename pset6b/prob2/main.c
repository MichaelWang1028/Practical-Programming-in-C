#include <stdio.h>
#include <string.h>
#include "hash.h"

int main()
{
  FILE* fp = fopen("book.txt", "r");
  char  word[1024]; /*big enough*/
  wordrec* wp = NULL;
  int i = 0;

  memset(table, 0, sizeof(table));
  /*read from input*/
  while(1)
  {
    if(fscanf(fp, "%s", word) != 1)
      break;
    wp = lookup(word, 1); /*create if doesn't exist*/
    wp->count++;
  }
  fclose(fp);

  /*
    print all words have frequency>100
   */
  for(i = 0; i < MAX_BUCKETS; i++)
    {
      for(wp = table[i]; wp != NULL; wp = wp->next)
	{
	  if(wp->count > 1000)
	    {
	      printf("%s-->%ld\n", wp->word, wp->count);
	    }
	}
    }
  cleartable();
  return 0;
}
