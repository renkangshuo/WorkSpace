#include "two_N.h"

#define N 8

int main()
{
	Local location = create_l(N);

	check(location);


	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

	check_one(location);
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	delete_step(2, location );
	check(location);
	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}
