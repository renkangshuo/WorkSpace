#include <stdio.h>
#include "list.h"

struct Node 
{
	int ele;
	Position Next;
};

void PrintList(List L);
int main() 
{
	struct Node Header;
	
	MakeEmpty( &Header);	
	printf("Is Header empty: \n");
	printf(" The answer is : %s\n", IsEmpty( &Header ) ? "Empty" : "No");

	printf("now, put something in that Header\n");

	for (int i = 0; i < 10; i++) {
			Insert( i, &Header, &Header);
	}

	printf("the content of that header are: \n");
 
	printf("Before...........................\n");
	
	PrintList( &Header );
	printf("<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
	printf("\n");
	
	
	Position P_I;
	P_I = Find ( 4, &Header);

	for (int i=0; i < 6; i++) {
		Insert( 88, &Header, P_I);
	}





	PrintList( &Header );

	DeleteList( &Header );

	printf("<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>\n");
	printf("\n");

	printf(" The answer is : %s\n", IsEmpty( &Header ) ? "Empty" : "No");
	
}

void PrintList( List L )
{
	Position P;
	P = L->Next;
	while ( P->Next != NULL)
	{	
		printf("%d > ", P->ele);
		P = P->Next;
	}
	printf("\n");
}
