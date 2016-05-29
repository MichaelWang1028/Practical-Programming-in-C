#include <stdio.h>
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
  unsigned int i;

  for (i = 0; str[i]; i++) {
    if (!is_character_a_delimiter(delims, str[i])) {
      break;
    }
  }

  return i;
}

bool is_character_a_delimiter(const char * delims, char ch)
{
  for (unsigned int j = 0; delims[j] != NULL_CHARACTER; j++) {
    if (strpos(delims, ch) != -1) {
      return true;
    }
  }

  return false;
}

unsigned int own_strcspn(const char * str, const char * delims)
{
  /* insert code here */
}

int strpos(const char * str, const char ch)
{
  for (unsigned int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ch) {
      return i;
    }
  }

  return -1;
}
