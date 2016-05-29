#ifndef STRING_TOKENS_H
#define STRING_TOKENS_H

#include <stdbool.h>

#define NULL_CHARACTER '\0'

char * strtok(char * text, const char * delims);

unsigned int own_strspn(const char * str, const char * delims);

unsigned int own_strcspn(const char * str, const char * delims);

int strpos(const char * str, const char ch);

bool is_character_a_delimiter(const char * delims, char ch);

#endif
