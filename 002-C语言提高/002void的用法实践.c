#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. void不能直接定义变量，因为编译器不知道分配多少内存给变量
// 当定义一个变量，编译器必须要知道分配多少内存
#if 0
struct Person
{
	char name[64];
	int age;
	struct Person p;
};

#endif

void test01()
{
	//void a;//错误的用法
	//struct Person p;
}


//2. 对函数返回的限定，对函数参数的限定
int fun(void)
{
	return 10;
}

void test02()
{
	//printf("ret = %d\n",fun(100,200));
}

//3. void*无类型指针
//所有类型指针的祖宗
//任何类型的指针都可以不经过强转 转换成void*类型
void test03()
{
	void *p = NULL;


	int *pInt = NULL;
	char *pChar = (char *)pInt;

	void *pVoid = pInt;
}

//void *主要用于数据结构的封装

int main()
{

	test02();

	system("pause");
	return EXIT_SUCCESS;
}