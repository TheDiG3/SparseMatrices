#include <iostream>
#include "OrthogonalLinkList.h"

using namespace std;

int main()
{
	OrthogonalLinkList S1(3,3);

	
	S1.insert(1, 1, 1);
	S1.insert(1, 2, 2);
	S1.insert(1, 3, 3);
	S1.insert(2, 1, 4);
	S1.insert(2, 2, 5);
	S1.insert(2, 3, 6);
	S1.insert(3, 1, 7);
	S1.insert(3, 2, 8);
	S1.insert(3, 3, 9);

	S1.insert(1, 1, 124);

	
	S1.display();
	return 0;
}