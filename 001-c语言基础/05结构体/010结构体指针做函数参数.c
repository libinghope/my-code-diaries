#include<stdio.h>
#include <string.h>

//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

//函数参数为结构体指针变量
void set_stu_pro(struct stu *tmp)
{
	strcpy(tmp->name, "mike");
	tmp->age = 18;
}

int main()
{
	struct stu s = { 0 };
	set_stu_pro(&s); //地址传递
	printf("s.name = %s, s.age = %d\n", s.name, s.age);

	return 0;
}
