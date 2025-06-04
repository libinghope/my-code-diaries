#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char name[64];
	int age;
	int ID;
	double score;
};

//规避地址传递的副作用(在使用对象指针的情况下，有可能意外修改数据)
//const 修饰*person,即指针指向的内存中的数据不能修改
void PrintPerson(const struct Person *person)
{

	//person->ID = 128;

	struct Person *p = (struct Person *)person;



	//p->ID = 128;

	printf("Name:%s Age:%d ID:%d Score:%f\n",person->name,person->age,person->ID,person->score);
	
}

void test()
{
	struct Person person = { "Trump", 30, 250, 59.9 };
	PrintPerson(&person);
}


int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}