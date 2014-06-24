#include "OrthogonalLinkList.h"


OrthogonalLinkList::OrthogonalLinkList(int rows, int columns)
{
	head_node = new Node(rows, columns, NULL);

	Node* ptr = head_node;

	for (int i = 1; i <= rows; i++)
	{
		ptr->next_row = new Node(i, NULL, NULL);
		ptr = ptr->next_row;
		ptr->next_column = ptr;

		if (i == rows)
		{
			ptr->next_row = head_node;
		}
	}

	ptr = head_node;

	for (int j = 1; j <= columns; j++)
	{
		ptr->next_column = new Node(NULL, j, NULL);
		ptr = ptr->next_column;
		ptr->next_row = ptr;
		

		if (j == columns)
		{
			ptr->next_column = head_node;
		}
	}
	
}


OrthogonalLinkList::~OrthogonalLinkList()
{
}

void OrthogonalLinkList::insert(int row, int column, int data)
{
	assert(row <= head_node->row && column <= head_node->column && row > 0 && column > 0);

	Node* ptr = head_node->next_row;
	

	while (ptr->row != row)
	{
		ptr = ptr->next_row;
	}
	Node* row_head = ptr;
	while (ptr->next_column != row_head && ptr->next_column->column < column)
	{
		ptr = ptr->next_column;
	}
	if (ptr->next_column->column == column && ptr->next_column != row_head)
	{
		ptr->next_column->data = data;
	}
	else
	{
		Node* newPtr = new Node(row, column, data);
		newPtr->next_column = ptr->next_column;
		ptr->next_column = newPtr;
		
		ptr = head_node->next_column;

		while (ptr->column != column)
		{
			ptr = ptr->next_column;
		}
		Node* column_head = ptr;
		while (ptr->next_row != column_head && ptr->next_row->row < row)
		{
			ptr = ptr->next_row;
		}
		newPtr->next_row = ptr->next_row;
		ptr->next_row = newPtr;
		
		newPtr = NULL;
	}
}
void  OrthogonalLinkList::display()const
{
	Node* ptr;
	ptr = head_node->next_row->next_column;


	for (int i = 1; i <= head_node->row; i++)
	{
		for (int j = 1; j <= head_node->column; j++)
		{
			if (ptr->column == j && ptr->row == i)
			{
				cout << ptr->data << "   ";
				ptr = ptr->next_column;
			}
 			else
			{
				cout << 0 << " ";
			}
 		}
		ptr = ptr->next_row;
		ptr = ptr->next_column;
		cout << endl;
	}

}