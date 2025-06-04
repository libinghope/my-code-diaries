#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>

#pragma pack(show)

struct A
{
	char a1; //0
	int a2; //4-7
};

void test01()
{

	struct A a = { 'b', 20 };
	printf("A.a2:%d\n", *(int *)((char *)&a + offsetof(struct A, a2)));
	printf("A.a2:%d\n",   *((int *)&a + 1)   );

}

struct C
{
	int a;
	double b;
};

struct B
{
	char a;
	int b;
	struct C c;
};

void test02()
{
	struct B b = { 'a', 20, 30, 3.14 };

	int off1 = offsetof(struct B, c);
	int off2 = offsetof(struct C, b);


	printf("%f\n", *(double *)(((char *)&b + off1) + off2));
	printf("%d\n", &(b.c.b));
	printf("%f\n", ((struct C *)((char *)&b + off1))->b );
}


//1. 第一个元素偏移量是0
//2. 从第二个元素开始计算偏移量

struct Student{
	int a; //0-3
	char b; //4-7
	double c; //8-15
	float d;//16-19
};

void test03()
{
	printf("%d\n", sizeof(struct Student));
}


int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}