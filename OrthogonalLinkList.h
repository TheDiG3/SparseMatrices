#ifndef _ORTHOGALLINKLIST_H_
#define _ORTHOGALLINKLIST_H_

#include "Node.h"
#include <iomanip>

class OrthogonalLinkList
{
public:
	OrthogonalLinkList(int rows, int columns);
	OrthogonalLinkList( const OrthogonalLinkList& _other );
	~OrthogonalLinkList();
	void insert(int row, int column, int data);
	void display()const;
	int getRows() const;
	int getColumns() const;

	/* Gets the element in the selected position */
	int getElementData( int _row , int _column ) const;
	OrthogonalLinkList operator +( const OrthogonalLinkList& _other ) const;
	OrthogonalLinkList& operator =( const OrthogonalLinkList& _rhs );

private:
	Node* head_node;

friend class Node;
};



#endif