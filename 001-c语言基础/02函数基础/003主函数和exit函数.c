#include <stdio.h>
#include <stdlib.h>

/*
在main函数中调用exit和return结果是一样的，但在子函数中调用return只
是代表子函数终止了，在子函数中调用exit，那么程序终止。
*/
void fun()
{
	printf("fun\n");
	//return;
	exit(0);//程序会退出,不在执行调用此函数后面的代码
}

int main()
{
	fun();
	while (1);

	return 0;
}
