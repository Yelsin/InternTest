#include <stdio.h>

char* strcpyMine(char* strDest, char* strSrc)
{
	if ((strDest==NULL) || (strSrc==NULL))
	{
		return NULL;
	}

	char* strDestCopy = strDest;
	while ((*strDest++ == *strSrc++) != '\0');

	return strDestCopy;
}

int main()
{
	char strSrc[] = "hello world";
	char strDest[30] = {0};

	strcpyMine(strDest, strSrc);

	printf("strDest = %s\n", strDest);

	return 0;
}