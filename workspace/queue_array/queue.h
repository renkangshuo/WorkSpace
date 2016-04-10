#ifndef _Queue1_h

#include <stdio.h>
#include <stdlib.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;

void check( Queue Q );
int is_empty( Queue Q );
int is_full( Queue Q );
Queue create( int maxelements );
void make_empty( Queue Q );
void enqueue( int x, Queue Q );
int front( Queue Q );
void dequeue( Queue Q );
int front_dequeue( Queue Q );

#endif


