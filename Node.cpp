#include "Node.h"


Node::Node(int row, int column, int data)
:row(row), column(column), data(data)
{
	next_row = NULL;
	next_column = NULL;
}

Node::~Node()
{
}
