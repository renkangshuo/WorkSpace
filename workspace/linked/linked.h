#inndef _List_H

struct Node;
typedef struct Node *ptrToNode;
typedef ptrToNode list;
typedef ptrToNode position;

list makeEmpty( list l );
int isEmpty( list l );
int isLast( position p, list l );
position find( int x, list l );
void delete1( int x, list l );
position findPrevious( int x, list l );
void insert( int x, list l, position p);
void deleteList( list l );
position Header( list l );
position first( list l );
position advance( position p );
int retrieve( position p );

#endif 	/* _List_H */

struct Node{
	int x;
	position next;
}
