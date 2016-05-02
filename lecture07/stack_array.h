#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

extern int stack_buffer[100];
extern int i_top;

void push(int elem);
int pop();
void print_stack();
int top();

#endif
