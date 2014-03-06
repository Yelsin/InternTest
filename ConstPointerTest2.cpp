#include <stdio.h>

int main()
{
	const char* node1 = "abc";
	char* const node2 = "abc";

	//node1[2] = 'k';
	//*node1[2] = 'k';
	//*node1 = "xyz";
	//node1 = "xyz";

	node2[2] = 'k';
	//*node2[2] = 'k';
	//*node2 = "xyz";
	//node2 = "xyz";

	return 0;
}