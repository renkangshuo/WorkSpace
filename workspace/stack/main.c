#include "stack.h"

int main()
{
	stack s;
	s = create_stack();
	
	push( 10, s);
	printf("push\n");
	check( s );

	push( 11, s);
	printf("push\n");
	check( s );
	
	push( 88, s);
	printf("push\n");
	check( s );

	printf("push\n");
	for (int i= 9; i > 0; i--)
		push(i, s);

	check( s );


	pop( s );
	printf("pop\n");
	check( s );
	pop( s );
	printf("pop\n");
	check( s );
	pop( s );
	printf("pop\n");

	check( s );



}
