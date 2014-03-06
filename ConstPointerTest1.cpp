#include <stdio.h>

void main()
{
	int a = 1;
	int b = 2;
	const int* p1 = &a; // 常量指针
	int* const p2 = &b; // 指针常量

	b += 1; // 变量b本身是可以修改的
	p1 = &b; // p1可以指向其他的变量，但是不管p1指向了谁，*p1都是不能修改的，此时*p1的值为3(即b+1)
	
	//*p1 = 100; // error! p1虽然现在指向了b,那么*p1就是3，不再是a的值，由于p1是个常量指针，不能对*p1进行修改

	//p2 = &a; // error！p2是一个指针常量，指针不能修改，但是*p2可以修改

	*p2 = 10;

	printf("*p1 = %d\n", *p1); // 输出 *p1 = 10，p1现在指向了b
	printf("*p2 = %d\n", *p2); // 输出 *p2 = 10
}