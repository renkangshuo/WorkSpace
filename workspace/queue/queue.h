#ifndef _Queue_h

#include <stdio.h>
#include <stdlib.h>

struct queue;
struct h_t;

typedef struct h_t* HT;
typedef struct queue* Q;

HT create_ht(void);
Q create(void);
void join(int x,HT ht);
int gone( HT ht);
void check(HT ht);

#endif


