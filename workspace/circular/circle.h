#ifndef _Circle_h

#include <stdio.h>
#include <stdlib.h>

struct circle;
struct position;

typedef struct circle* C;
typedef struct position* P;

P create_p(void);
C create(void);
void join(int x, P p);
int gone( P p);
void check(P p);

#endif


