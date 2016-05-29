#include "string_tokens.h"

static char * pnexttoken;

char * strtok(char * text, const char * delims)
{
  /* initialize */
  if (!text) {
    text = pnexttoken;
  }
  /* find start of token in text */
  text += strspn(text, delims);
  if (*text == '\0')
    return NULL;
  /* find end of token in text */
  pnexttoken = text + strcspn(text, delims);
  /* insert null−terminator at end */
  if (*pnexttoken != '\0')
    *pnexttoken++ = '\0' ;
  return text;
}

unsigned int strspn(const char * str, const char * delims)
{
  /* insert code here */
}

unsigned int strcspn(const char * str, const char * delims)
{
  /* insert code here */
}
