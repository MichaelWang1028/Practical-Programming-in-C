#include <stdio.h>
#include "string_tokens.h"

int main(void)
{
  char str[80] = "This is - www.tutorialspoint.com - website. A really good nice, clear page.";
   const char * delims  = "- .,";
   char *token;

   /* get the first token */
   token = strtok(str, delims);

   /* walk through other tokens */
   while( token != NULL )
   {
      printf("%s\n", token );

      token = strtok(NULL, delims);
   }

   return(0);
}
