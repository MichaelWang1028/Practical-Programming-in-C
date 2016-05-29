#include <stdlib.h>
#include "string_tokens.h"

static char * pnexttoken;

char * strtok(char * text, const char * delims)
{
  /* initialize */
  if (!text) {
    text = pnexttoken;
  }
  /* find start of token in text */
  text += own_strspn(text, delims);
  if (*text == NULL_CHARACTER)
    return NULL;
  /* find end of token in text */
  pnexttoken = text + own_strcspn(text, delims);
  /* insert null−terminator at end */
  if (*pnexttoken != NULL_CHARACTER)
    *pnexttoken++ = NULL_CHARACTER;
  return text;
}

unsigned int own_strspn(const char * str, const char * delims)
{
  /* insert code here */
}

unsigned int own_strcspn(const char * str, const char * delims)
{
  /* insert code here */
}
