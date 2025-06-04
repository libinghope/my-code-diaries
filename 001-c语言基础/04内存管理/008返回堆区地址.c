#include <stdio.h>
#include <stdlib.h>

int *fun()
{
	int *tmp = NULL;
	tmp = (int *)malloc(sizeof(int));
	*tmp = 100;
	return tmp;//返回堆区地址，函数调用完毕，不释放
}

int main(int argc, char *argv[])
{
	int *p = NULL;
	p = fun();
	printf("*p = %d\n", *p);//ok

	//堆区空间，使用完毕，手动释放
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	return 0;
}
