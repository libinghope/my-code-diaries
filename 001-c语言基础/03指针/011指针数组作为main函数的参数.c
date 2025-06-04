/*
	main函数是操作系统调用的，第一个参数标明argv数组的成员数量，
    argv数组的每个成员都是char *类型
	argv是命令行参数的字符串数组
	argc代表命令行参数的数量，程序名字本身算一个参数

*/
#include <stdio.h>
#include <stdlib.h>

//argc: 传参数的个数（包含可执行程序）
//argv：指针数组，指向输入的参数
int main(int argc, char *argv[])
{

	//指针数组，它是数组，每个元素都是指针
	char *a[] = { "aaaaaaa", "bbbbbbbbbb", "ccccccc" };
	int i = 0;

	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

    system("pause");
	return 0;
}
