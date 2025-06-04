#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1. sizeof返回的是变量实际所占用空间的大小，单位字节
//#pragma pack(1)
struct Person
{
	char a;
	int b;
};
void test01()
{
	
	printf("int size:%d\n",sizeof(int));
	double a = 3.14;
	printf("a size:%d\n", sizeof a);

	printf("Person size:%d\n",sizeof(struct Person));

}

//2. sizeof返回结果是unsigned int
void test02()
{
	unsigned int a = 10;
	if (a - 20 > 0)
	{
		printf("大于0\n");
	}
	else
	{
		printf("小于0\n");
	}


	if (sizeof(int) -5  < 0)
	{
		printf("< 0\n");
	}
	else
	{
		printf("> 0\n");
	}
}


//1. sizeof计算数组
//数组作为函数参数会退化为指向数组首元素的指针
int caculateArraySize(int arr[])
{
	return sizeof(arr);
}
void test03()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	printf("sizeof arr:%d\n", sizeof(arr));
	printf("sizeof arr:%d\n", caculateArraySize(arr));
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}