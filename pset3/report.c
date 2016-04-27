#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIELD_SIZE 100
#define FIELDS 9
#define INPUT_FILE_NAME "stateoutflow0708.txt"
#define ERROR_MESSAGE "Input file couldn't be read.\n"
#define OUTPUT stdout


void print_separation(int n);
void print_table_header();
void print_table_bottom(long total_migration);

int main() {

  FILE * emigration_data = fopen(INPUT_FILE_NAME, "r");

  if (emigration_data == NULL) {
    fprintf(stderr, "%s\n", ERROR_MESSAGE);
    exit(-1);
  }

  char line[FIELD_SIZE * FIELDS];
  char state_code_origin[FIELD_SIZE];
  char country_code_origin[FIELD_SIZE];
  char state_code_destination[FIELD_SIZE];
  char country_code_destination[FIELD_SIZE];
  char state_abbreviation[FIELD_SIZE];
  char state_name[FIELD_SIZE];
  int return_number;
  int exmpt_nummber;
  int agrr_AGI;
  long total_migration = 0;

  fgets(line, FIELD_SIZE * FIELDS, emigration_data);
  print_table_header();

  while (fscanf(emigration_data, "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d",
                state_code_origin, country_code_origin, state_code_destination,
                country_code_destination, state_abbreviation, state_name,
                &return_number, &exmpt_nummber, &agrr_AGI) != EOF) {

    if (strcmp("\"25\"", state_code_origin) == 0) {
      total_migration += agrr_AGI;
      fprintf(OUTPUT, "%-25s%10d\n", state_name, agrr_AGI);
    }
  }

  print_table_bottom(total_migration);

  fclose(emigration_data);

  return 0;
}

void print_table_header() {
  fprintf(OUTPUT, "%-25s%10s\n", "STATE", "TOTAL");
  print_separation(35);
}

void print_table_bottom(long total_migration)
{
  print_separation(35);
  fprintf(OUTPUT, "%-25s%10lu\n", "TOTAL", total_migration);
}

void print_separation(int n)
{
  for (int i = 0; i < n; i++) {
    fprintf(OUTPUT, "%c", '-');
  }
  fprintf(OUTPUT, "\n");
}
