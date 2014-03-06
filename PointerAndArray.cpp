#include <stdio.h>

int main()
{
	char* str[] = {"Welcome", "to", "Fortemedia", "Nanjing"};
	char **p = str + 1;
	str[0] = (*p++) + 2;
	str[1] = *(p+1);
	str[2] = p[1] + 3;

	printf("str[2] = %s\n", str[2]);
	printf("str[1] = %s\n", str[1]);
	printf("%d\n", str[2]-str[1]);

	str[3] = p[0] + (str[2] - str[1]);

	printf("p[0] = %s\n", p[0]);
	printf("p[1] = %s\n", p[1]);
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);

	return 0;
}