#ifndef _Stack_h
#include <stdio.h>
#include <stdlib.h>

struct stack_record;
typedef struct stack_record* stack;

int is_empty( stack s );
int is_full( stack s );
stack create_stack( int max_elements );
void dispose_stack( stack s );
void make_empty( stack s );
void push( int x, stack s );
int top( stack s );
void pop( stack s );
int top_pop( stack s );

#endif /* _Stack_h */
