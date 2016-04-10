#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node{
	int ele;
	Position Next;
};

int MakeEmpty( List L )
{
	L->Next = NULL;
	return 0;
}
void FatalError(char *msgs)
{
	printf("%s\n", msgs);
}

/* Return true if L is empty */

int IsEmpty( List L )
{
	return L->Next == NULL;
}


/* Return true if P is the last position in List L */
/* Parameter L is unused in this implementation */

int IsLast( Position P, List L )
{
	return P->Next == NULL;
}

/* Return Position of X in L; NULL if not found */

Position Find( int X, List L )
{
	Position P;

	P = L->Next;
	while( P != NULL && P->ele != X )
		P = P->Next;

	return P;
}

/* Delete first occurence of X from a list */
/* Assume use of a header node */

void Delete( int X, List L )
{
	Position P, TmpCell;
	
	P = FindPrevious( X, L);

	if ( !IsLast( P, L ))  /* Assumption of header use */
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free( TmpCell );
	}
}


/* If X is not found , then Next field of returned 
 * Position is NULL
 * Assume a Header
 */

Position FindPrevious( int X, List L)
{
	Position P;

	P = L;
	while ( P->Next != NULL && P->Next->ele != X)
		P = P->Next;

	return P;
}

/* Correct DeleteList algorithm */

void DeleteList( List L )
{
	Position P, Tmp;

	P = L->Next; /* Header assumed */
	L->Next = NULL;
	while( P != NULL )
	{
		Tmp = P->Next;
		free( P );
		P = Tmp;
	}
}

/* Insert (after legal position p) 
 *Header imlementation assumed 
 Parameter L is unused in this implementation 
 */
void Insert( int X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc( sizeof( struct Node) );
	if (TmpCell == NULL)
		FatalError( "Out of Space!!!");

	TmpCell->ele = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
