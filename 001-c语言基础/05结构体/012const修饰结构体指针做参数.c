#include <stdio.h>
//结构体类型的定义
struct stu
{
	char name[50];
	int age;
};

void fun1(struct stu * const p)
{
	//p = NULL; //err
	p->age = 10; //ok
}

//void fun2(struct stu const*  p)
void fun2(const struct stu *  p)
{
	p = NULL; //ok
	//p->age = 10; //err
}

void fun3(const struct stu * const p)
{
	//p = NULL; //err
	//p->age = 10; //err
}

int main(){

    return 0;
}
