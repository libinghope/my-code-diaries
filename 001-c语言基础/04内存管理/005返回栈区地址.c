#include <stdio.h>
//以下代码在linux中测试
int a = 10;
int *fun()
{
	
	return &a;//函数调用完毕，a释放
}

int main(int argc, char *argv[])
{
	int *p = NULL;
	p = fun();  
	*p = 100; //操作野指针指向的内存,err

	return 0;
}
