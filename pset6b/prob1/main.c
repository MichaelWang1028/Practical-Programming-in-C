#include <stdio.h>
#include "callback.h"

int main()
{
  int nstudents = sizeof(class) / sizeof(student);
  int age;

  puts("Raw records:");
  puts("-------------------------------");
  apply(class, nstudents, printrec, NULL);

  /*sort based on first name*/
  puts("Sorted by first name:");
  puts("-------------------------------");
  qsort(class, nstudents, sizeof(student), compare_first_name);
  apply(class, nstudents, printrec, NULL);

  /*sort based on last name*/
  puts("Sorted by last name:");
  puts("-------------------------------");
  qsort(class, nstudents, sizeof(student), compare_last_name);
  apply(class, nstudents, printrec, NULL);

  /*print people older than 20*/
  puts("People older than 20:");
  puts("-------------------------------");
  age = 20;
  apply(class, nstudents, isolder, &age);
  return 0;
}
