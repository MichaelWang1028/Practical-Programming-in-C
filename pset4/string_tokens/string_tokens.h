#ifndef STRING_TOKENS_H
#define STRING_TOKENS_H

#define NULL_CHARACTER '\0'

char * strtok(char * text, const char * delims);

unsigned int strspn(const char * str, const char * delims);

unsigned int strcspn(const char * str, const char * delims);

#endif
