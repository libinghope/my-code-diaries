#include<stdio.h>

//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

int main()
{
	struct stu s1 = { "lily", 18 };

	//如果是指针变量，通过->操作结构体成员
	struct stu *p = &s1;
	printf("p->name = %s, p->age=%d\n", p->name, p->age);
	printf("(*p).name = %s, (*p).age=%d\n",  (*p).name,  (*p).age);

	return 0;
}
