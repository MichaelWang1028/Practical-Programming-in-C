#ifndef STRING_TOKENS_H
#define STRING_TOKENS_H

#define NULL_CHARACTER '\0'

char * strtok(char * text, const char * delims);

unsigned int own_strspn(const char * str, const char * delims);

unsigned int own_strcspn(const char * str, const char * delims);

#endif
