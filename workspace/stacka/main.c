#include "stacka.h"

int main()
{
	stack s;
	s = create_stack( 20 );
	for ( int i=0; i < 9; i++)
		push(i, s);
	printf("%d \n", top( s ));
	for (int i=0; i < 20; i++)
		printf("%d\n", top_pop( s ));
}
