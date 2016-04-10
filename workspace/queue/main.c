#include "queue.h"

int main() 
{
	HT ht = create_ht();
	
	check(ht);
	gone(ht);
	gone(ht);
	check(ht);
	join(888, ht);
	join(999, ht);
	join(111, ht);
	join(222, ht);
	check(ht);
	gone(ht);
	gone(ht);
	gone(ht);
	gone(ht);
	gone(ht);
	gone(ht);
	gone(ht);
	check(ht);
}
