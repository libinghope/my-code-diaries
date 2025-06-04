#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. 栈区的内存自动申请自动释放，不需要程序手动管理

int* myFunc()
{
	//不要返回局部变量的地址,出了这个函数就销毁了
	int a = 10; //栈上
	return &a;
}

void test01()
{
	//局部变量a的内存已经被回收
	int *p = myFunc();
	printf("*p = %d\n",*p);
}



char *getString()
{
	char str[] = "hello world!";

	return str;
}

void test02()
{
	char *s = NULL;

	s = getString();

	printf("s = %s\n",s);
}


int main(){

	//test01();

    printf("getString = %s \n", getString());
	test02();

	system("pause");
	return EXIT_SUCCESS;
}