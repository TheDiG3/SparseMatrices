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

private:
	Node* head_node;

friend class Node;
};



#endif