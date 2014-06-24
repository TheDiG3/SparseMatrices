#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <cassert>

using namespace std;

class List;
class Iterator;

class Node
{
public:
	/**
	Constructs a node with a given data value.
	@param s the data to store in this node
	*/
	Node(int row, int column, int data);
	~Node();

private:
	int row;
	int column;
	int data;
	Node* next_row;
	Node* next_column;


	friend class OrthogonalLinkList;
};
#endif