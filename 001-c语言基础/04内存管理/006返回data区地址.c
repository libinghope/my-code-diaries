#include <stdio.h>

int *fun()
{
	static int a = 10;
	return &a; //函数调用完毕，a不释放
}

int main(int argc, char *argv[])
{
	int *p = NULL;
	p = fun();
	*p = 100; //ok
	printf("*p = %d\n", *p);

	return 0;
}
