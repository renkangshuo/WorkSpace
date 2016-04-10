#ifndef _TWO_OF_H
#include <stdio.h>
#include <stdlib.h>

struct node;
struct local;

typedef struct local* Local;
typedef struct node* Node;


/* Create a situation that invloves some people */
Local create_l(int total);

/* Delete people by certain steps */
void delete_step(int step, Local location);

/* Check */
void check(Local location);

/* Check one */
void check_one(Local location);

/* Create a node whose next points to itself */
Node create_n();

#endif


