#include<stdio.h>
#include <string.h>

//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

//函数参数为结构体普通变量
void set_stu(struct stu tmp)
{
	strcpy(tmp.name, "mike");
	tmp.age = 18;
	printf("tmp.name = %s, tmp.age = %d\n", tmp.name, tmp.age);
}

int main()
{
	struct stu s = { 0 };
	set_stu(s); //值传递
	printf("s.name = %s, s.age = %d\n", s.name, s.age);

	return 0;
}
