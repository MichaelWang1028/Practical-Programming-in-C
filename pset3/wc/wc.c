#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool is_space_or_nul(char c);

int main(int argc,char* argv[])
{
  FILE* file_pointer = NULL;
  int   number_of_files = --argc; /*ignore the name of the program itself*/
  int   argidx = 1;      /*ignore the name of the program itself*/
  char* current_file = "";
  char  character, previous_character;

  unsigned long number_of_words = 0;
  unsigned long number_of_lines = 0;
  unsigned long number_of_characters = 0;

  if(number_of_files == 0)
  {
    file_pointer = stdin; /*standard input*/
    number_of_files++;
  }
  else /*set to first*/
  {
    current_file = argv[argidx++];
    file_pointer = fopen(current_file, "r");
  }

  while(number_of_files > 0) /*files left >0*/
  {
    if(file_pointer == NULL)
    {
      fprintf(stderr, "Unable to open input\n");
      exit(-1);
    }

    number_of_characters = number_of_words = number_of_lines = 0;
    previous_character = 0;


    while((character = getc(file_pointer))!=EOF)
    {
      number_of_characters++;
      if (character == '\n') {
        number_of_lines++;
      }

      if (!is_space_or_nul(previous_character)  && isspace(character)) {
        number_of_words++;
      }

      previous_character = character;
    }

    if (!is_space_or_nul(previous_character)) {
        number_of_words++;
    }

    printf("\n%ld\t%ld\t%ld\t%s\n", number_of_lines, number_of_words, number_of_characters, current_file);
    /*next file if exists*/
    number_of_files--;
    if(number_of_files > 0)
    {
      current_file = argv[argidx++];
      file_pointer = fopen(current_file,"r");
    }
  }

	return 0;
}

bool is_space_or_nul(char c) {
  return isspace(c) || c == 0;
}
