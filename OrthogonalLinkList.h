#ifndef _ORTHOGALLINKLIST_H_
#define _ORTHOGALLINKLIST_H_

#include "Node.h"

class OrthogonalLinkList
{
public:
	OrthogonalLinkList(int rows, int columns);
	~OrthogonalLinkList();
	void insert(int row, int column, int data);
	void display()const;

	/* Gets the element in the selected position */
	int getElementData( int _row , int _column ) const;
	OrthogonalLinkList& operator +( const OrthogonalLinkList& _other );

private:
	Node* head_node;

friend class Node;
};



#endif