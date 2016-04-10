#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

int MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( int x, List L );
void Delete( int x, List L );
Position FindPrevious( int x, List L);
void Insert( int x, List L , Position P);
void DeleteList( List L );
Position Header( List L );
Position First ( List L );
Position Advanced( List L );
int Retrieve( Position P );

#endif 		/* _List_H */


/* Place in the implementation file */
/*struct Node
{
	int ele;
	Position Next;
}; */
