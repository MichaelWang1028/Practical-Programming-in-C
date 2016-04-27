#include <stdio.h>
#include <string.h>

int main()
{
  char s[20] = "Hello my friend";
  char another_s[20] = "Miguel Vargas";
  char *ps = s;


  strcat(ps, " ");
  strncat(ps, another_s, 6);

  puts(ps);

  return 0;
}
