#include "OrthogonalLinkList.h"


OrthogonalLinkList::OrthogonalLinkList( int rows , int columns )
{
	head_node = new Node( rows , columns , NULL );

	Node* ptr = head_node;

	for ( int i = 1; i <= rows; i++ )
	{
		ptr->next_row = new Node( i , NULL , NULL );
		ptr = ptr->next_row;
		ptr->next_column = ptr;

		if ( i == rows )
		{
			ptr->next_row = head_node;
		}
	}

	ptr = head_node;

	for ( int j = 1; j <= columns; j++ )
	{
		ptr->next_column = new Node( NULL , j , NULL );
		ptr = ptr->next_column;
		ptr->next_row = ptr;


		if ( j == columns )
		{
			ptr->next_column = head_node;
		}
	}
}

OrthogonalLinkList::OrthogonalLinkList( const OrthogonalLinkList& _other )
{
	int rows = _other.getRows();
	int columns = _other.getColumns();

	head_node = new Node( rows , columns , NULL );

	Node* ptr = head_node;

	for ( int i = 1; i <= rows; i++ )
	{
		ptr->next_row = new Node( i , NULL , NULL );
		ptr = ptr->next_row;
		ptr->next_column = ptr;

		if ( i == rows )
		{
			ptr->next_row = head_node;
		}
	}

	ptr = head_node;

	for ( int j = 1; j <= columns; j++ )
	{
		ptr->next_column = new Node( NULL , j , NULL );
		ptr = ptr->next_column;
		ptr->next_row = ptr;


		if ( j == columns )
		{
			ptr->next_column = head_node;
		}
	}

	// Copy the elements values of the other matrix.
	for ( int cycle_row = 1; cycle_row <= rows; cycle_row++ )
	{
		for ( int cycle_column = 1; cycle_column <= columns; cycle_column++ )
		{
			this->insert( cycle_row , cycle_column , _other.getElementData( cycle_row , cycle_column ) );
		}
	}
}

/**
 * This needs to take care of deleting and freeing the memory occupied by each node of the matrix.
 */
OrthogonalLinkList::~OrthogonalLinkList()
{
	Node* local_current_row_header = this->head_node;
	Node* local_next_row_header = NULL;
	Node* local_current_node_to_delete = NULL;
	Node* local_next_node_to_delete = NULL;

	// I will delete all the nodes from top-left to bottom-right.
	// I save a reference to the next row to be deleted, delete the current row 
	// I'm at and advance to the next one till every node is cleared.
	do
	{
		// The next header will be shifted down one row.
		// I save the next row header reference here because in the next cycle
		// it's going to be the first node to be deleted.
		local_next_row_header = local_current_row_header->next_row;
		local_current_node_to_delete = local_current_row_header;
		do
		{
			local_next_node_to_delete = local_current_node_to_delete->next_column;
			delete local_current_node_to_delete;
			local_current_node_to_delete = local_next_node_to_delete;

		} while ( local_next_node_to_delete != local_current_row_header );

		// Shift down the row reference to be deleted next.
		local_current_row_header = local_next_row_header;
	} while ( local_next_row_header != this->head_node ); // When the next node address is the same as the matrix header we have finished the deletion of all the rows.
}

OrthogonalLinkList& OrthogonalLinkList::operator=( const OrthogonalLinkList& _rhs )
{
	// Check for self assignment
	if ( this != &_rhs )
	{
		this->~OrthogonalLinkList();
		int rows = _rhs.getRows();
		int columns = _rhs.getColumns();

		head_node = new Node( rows , columns , NULL );

		Node* ptr = head_node;

		for ( int i = 1; i <= rows; i++ )
		{
			ptr->next_row = new Node( i , NULL , NULL );
			ptr = ptr->next_row;
			ptr->next_column = ptr;

			if ( i == rows )
			{
				ptr->next_row = head_node;
			}
		}

		ptr = head_node;

		for ( int j = 1; j <= columns; j++ )
		{
			ptr->next_column = new Node( NULL , j , NULL );
			ptr = ptr->next_column;
			ptr->next_row = ptr;


			if ( j == columns )
			{
				ptr->next_column = head_node;
			}
		}

		// Copy the elements values of the other matrix.
		for ( int cycle_row = 1; cycle_row <= rows; cycle_row++ )
		{
			for ( int cycle_column = 1; cycle_column <= columns; cycle_column++ )
			{
				this->insert( cycle_row , cycle_column , _rhs.getElementData( cycle_row , cycle_column ) );
			}
		}
	}
	return *this;

}

/* Sums two matrices. Outputs an error to console and throws if the two matrices are not equal in columns/rows. */
OrthogonalLinkList OrthogonalLinkList::operator+( const OrthogonalLinkList& _other ) const
{
	// Throws if the two matrices are not equal in dimensions
	if ( ( this->getColumns() != _other.getColumns() ) || ( this->getRows() != _other.getRows() ) )
	{
		throw;
	}

	int local_row_limit = this->head_node->row;
	int local_column_limit = this->head_node->column;

	int temp_sum_value;

	OrthogonalLinkList return_summed_list = OrthogonalLinkList( this->getRows() , this->getColumns() );

	// I just scan all the positions in the two orthogonal lists for the value at each position and sum the two.
	for ( int cycle_row = 1; cycle_row <= local_row_limit; cycle_row++ )
	{
		for ( int cycle_column = 1; cycle_column <= local_column_limit; cycle_column++ )
		{
			temp_sum_value = this->getElementData( cycle_row , cycle_column ) + _other.getElementData( cycle_row , cycle_column );
			return_summed_list.insert( cycle_row , cycle_column , temp_sum_value );
		}
	}
	return return_summed_list;
}


int OrthogonalLinkList::getRows() const
{
	return this->head_node->row;
}

int OrthogonalLinkList::getColumns() const
{
	return this->head_node->column;
}

int OrthogonalLinkList::getElementData( int _row , int _column ) const
{
	Node* local_working_pointer = head_node->next_row;

	// We are trying to access an element outside the bounds. Should report an error.
	if ( head_node->row < _row || head_node->column < _column )
	{
		throw;
	}

	// Gets to the selected row.
	while ( local_working_pointer->row != _row )
	{
		local_working_pointer = local_working_pointer->next_row;
		if ( local_working_pointer->row > _row ) // Since the row we are searching for is not present I can just return an "empty" element: 0.
		{
			return 0;
		}

		// If we end up being at the beginning of the list it means the selected row was not found. 
		if ( local_working_pointer == head_node )
		{
			return 0;
		}
	}

	Node* temp_current_column_head = local_working_pointer;

	// Gets to the selected column.
	while ( local_working_pointer->column != _column )
	{
		local_working_pointer = local_working_pointer->next_column;
		if ( local_working_pointer->column > _column ) // Since the column we are searching for is not present I can just return an "empty" element: 0.
		{
			return 0;
		}

		// If we end up being at the beginning of the list it means the selected row was not found.
		if ( local_working_pointer == temp_current_column_head )
		{
			return 0;
		}
	}

	return local_working_pointer->data;
}

void OrthogonalLinkList::insert( int row , int column , int data )
{
	assert( row <= head_node->row && column <= head_node->column && row > 0 && column > 0 );

	Node* ptr = head_node->next_row;


	while ( ptr->row != row )
	{
		ptr = ptr->next_row;
	}
	Node* row_head = ptr;
	while ( ptr->next_column != row_head && ptr->next_column->column < column )
	{
		ptr = ptr->next_column;
	}
	if ( ptr->next_column->column == column && ptr->next_column != row_head )
	{
		ptr->next_column->data = data;
	}
	else
	{
		Node* newPtr = new Node( row , column , data );
		newPtr->next_column = ptr->next_column;
		ptr->next_column = newPtr;

		ptr = head_node->next_column;

		while ( ptr->column != column )
		{
			ptr = ptr->next_column;
		}
		Node* column_head = ptr;
		while ( ptr->next_row != column_head && ptr->next_row->row < row )
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
				cout << setw(5) << ptr->data;
				ptr = ptr->next_column;
			}
			else
			{
				cout << setw(5) << 0;
			}
		}
		ptr = ptr->next_row;
		ptr = ptr->next_column;
		cout << endl;
	}
	cout << endl;

}

