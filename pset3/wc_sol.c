#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  FILE* fp=NULL;
  int nfiles = --argc;
  int argidx = 1;
  char* currfile = "";
  char c;

  enum state {INSIDE, OUTSIDE};
  enum state currstate = INSIDE;

  unsigned long nw=0, nl =0,nc=0;
  if ( nfiles ==0)
  {
    fp = stdin;
    nfiles++;
  }
  else
  {
    currfile = argv[argidx++];
    fp=fopen( currfile, "r" );
  }
  while ( nfiles >0)
  {
    if ( fp == NULL)
    {
      fprintf( stderr , "Unable to open input\n" );
      exit(-1);
    }
    nc=nw=nl =0;
    while (( c = getc(fp)) != EOF)
    {
      nc++;
      if (c =='\n')
      {
        nl++;
      }

      if ( isspace(c))
      {
        if ( currstate==INSIDE)
          nw++;
        currstate=OUTSIDE;
      }
      else
      {
        currstate = INSIDE ;
      }
    }
    printf("%ld %ld %ld %s\n" , nl , nw, nc , currfile);
    nfiles--;

    if (nfiles > 0)
    {
      currfile = argv [argidx++];
      fp =fopen ( currfile , "r" );
    }
  }
}
