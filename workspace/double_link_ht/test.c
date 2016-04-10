#include "double.h"

int main()
{
	struct ht* htp;

	htp = create_ht();

	insert_at_head( 888, htp);
	insert_at_head( 999, htp);
	
	insert_at_tail( 000, htp);
	insert_at_tail( 777, htp);
	insert_at_tail( 789, htp);

	check_from_head(htp);
	check_from_tail(htp);

	printf("\n.>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

	delete_at_head(htp);

	delete_at_tail(htp);

	check_from_head(htp);
	check_from_tail(htp);

}
