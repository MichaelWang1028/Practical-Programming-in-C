#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
  short s;
  union u {
    int i;
    char c;
  } u;
  unsigned int flag_s: 1;
  unsigned int flat_u: 2;
  unsigned int bar;
} foo;

typedef struct {
  union t {
    int i;
    char c;
  } t;
  unsigned int bar;
  short s;
  unsigned int flag_s: 1;
  unsigned int flat_u: 2;

} foo2;

#endif
