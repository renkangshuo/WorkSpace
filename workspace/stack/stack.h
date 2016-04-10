#ifndef _Stack_h
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* ptr_node;
typedef ptr_node stack;

int is_empty( stack s );
stack create_stack( void );
void dispose_stack( stack s);
void make_empty( stack s) ;
void push( int x, stack s);
int top( stack s);
void pop( stack s);
void check( stack s );

#endif /* _Stack_h */

/* Place in implementation file */
/* stack implementation is a linked list with a header */

