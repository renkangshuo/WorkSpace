#include "queue.h"

int main()
{
	Queue Q = create( 10 );
	enqueue( 888, Q );
	enqueue( 999 , Q);
	
	check( Q );
}
