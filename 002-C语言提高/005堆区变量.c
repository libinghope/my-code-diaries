#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//1. 堆的内存成员手动申请，手动释放。
int *getSpace()
{
	int *p = malloc(sizeof(int) * 5);
	if (NULL == p)
	{
		return NULL;
	}

	int  j = 0;
	
	//只要是连续的内存空间，都能使用下标的方式访问内存
	for (int i = 0; i < 5; ++i)
	{
		p[i] = 100 + i;
	}

	return p;
}

void test01()
{
	int *ret = getSpace();
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ",ret[i]);
	}

	//用完堆内存，一定要释放
	free(ret);
	ret = NULL;

}

//2.
//定义变量的时候一定要初始化，很多的Bug产生都是由于没有初始化造成的。
void allocateSpace(char *p)
{
	p = malloc(100);
	memset(p,0,100);
	strcpy(p, "hello world!");
}

void test02()
{
	char *p = NULL;
	allocateSpace(p);
	printf("p = %s\n",p);
}


void allocateSpace02(char **p)
{

	char *temp = malloc(100);
	memset(temp, 0, 100);
	strcpy(temp, "hello world!");

	*p = temp;
}

void test03()
{
	char *p = NULL;
	allocateSpace02(&p);
	printf("p = %s\n", p);
}


int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}