#include <stdio.h>
#include <stdlib.h>

void fun(int *tmp)
{
	tmp = (int *)malloc(sizeof(int));
	*tmp = 100;
}

int main(int argc, char *argv[])
{
	int *p = NULL;
	fun(p); //值传递，形参修改不会影响实参
	printf("*p = %d\n", *p);//err，操作空指针指向的内存

	return 0;
}
