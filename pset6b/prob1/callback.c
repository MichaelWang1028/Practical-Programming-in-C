#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "callback.h"

student class[10] = {
  "Sean","Penn",2,21,
  "Sean","Connery",4,25,
  "Angelina","Jolie",3,22,
  "Meryl","Streep",4,29,
  "Robin","Williams",3,32,
  "Bill","Gates",3,17,
  "Jodie","Foster",4,25,
  "John","Travolta",1,17,
  "Isaac","Newton",2,19,
  "Sarah","Palin",2,19
};


/*
  TODO
  @function compare_first_name
  @desc     compares first name of two records.
*/
int compare_first_name(const void* a,const void* b)
{
  return 1; /*place holder for now*/
}

/*
  TODO
  @function compare_last_name
  @desc     compares last name of two records.
*/
int compare_last_name(const void* a,const void* b)
{

  return 1; /*place holder for now*/

}

/*!
  @function apply
  @desc     applies
 */
void apply(student* sarr,int nrec,void (*fp)(void* prec,void* arg),void* arg)
{
  int i=0;
  for(i=0;i<nrec;i++)
    {
      /*callback*/
      fp(&sarr[i],arg);
    }
}

/*
  @function printrec
  @desc     prints student record
*/
void printrec(void* prec,void* arg)
{
  student* pstud=(student*)prec;
  printf("%-20s %-20s %2d %2d\n",pstud->fname,pstud->lname,pstud->year,pstud->age);
}


/*
  @function isolder
  @desc     prints student record onlyl if the student is older than *((int*)arg)
  NOTE: use the same format as
*/
void isolder(void* prec,void* arg)
{

}
