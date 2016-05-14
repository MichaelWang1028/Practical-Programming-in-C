#ifndef CALLBACK_H
#define CALLBACK_H

#define NUMBER_OF_STUDENTS 10
#define STRING_LENGTH 100

typedef struct
{
  char fname[STRING_LENGTH];
  char lname[STRING_LENGTH];
  int  year;
  int  age;
} student;

extern student class[NUMBER_OF_STUDENTS];

/*
  TODO
  @function compare_first_name
  @desc     compares first name of two records.
*/
int compare_first_name(const void* a, const void* b);

/*
  TODO
  @function compare_last_name
  @desc     compares last name of two records.
*/
int compare_last_name(const void* a, const void* b);

/*!
  @function apply
  @desc     applies
 */
void apply(student* sarr, int nrec, void (*fp)(void* prec, void* arg), void* arg);

/*
  @function printrec
  @desc     prints student record
*/
void printrec(void* prec, void* arg);

/*
  @function isolder
  @desc     prints student record onlyl if the student is older than *((int*)arg)
  NOTE: use the same format as
*/
void isolder(void* prec, void* arg);

#endif
