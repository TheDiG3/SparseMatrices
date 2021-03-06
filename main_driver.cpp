#include <iostream>
#include "OrthogonalLinkList.h"

using namespace std;

int main()
{
	OrthogonalLinkList S1( 4 , 3 );
	OrthogonalLinkList S2( 4 , 3 );

	S1.insert( 1 , 1 , 1 );
	S1.insert( 1 , 2 , 2 );
	S1.insert( 1 , 3 , 3 );
	S1.insert( 2 , 1 , 4 );
	S1.insert( 2 , 2 , 5 );
	S1.insert( 2 , 3 , 6 );
	S1.insert( 3 , 1 , 7 );
	S1.insert( 3 , 2 , 8 );
	S1.insert( 3 , 3 , 9 );

	cout << "First Matrix:" << endl;
	S1.display();
	cout << endl;

	S2.insert( 1 , 1 , 100 );
	S2.insert( 1 , 2 , 2134 );
	S2.insert( 1 , 3 , 313 );
	S2.insert( 2 , 1 , 2 );
	S2.insert( 4 , 3 , 1 );
	cout << "Second Matrix:" << endl;

	S2.display();
	OrthogonalLinkList S3 = S1 + S2;
	cout << endl;
	cout << "Sum Matrix:" << endl;



	S3.display();

 	return 0;
}