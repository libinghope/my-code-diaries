#include<iostream>
using namespace std;

/*
	指向类静态数据成员的指针
指向静态数据成员的指针的定义和使用与普通指针相同，在定义时无须和类相关联，在使用时也无须和具体的对象相关联。
	指向类静态成员函数的指针
指向静态成员函数的指针和普通指针相同，在定义时无须和类相关联，在使用时也无须和具体的对象相关联·
*/
class A{
public:
	static void dis(){
		cout << data << endl;
	}
	static int data;
};

int A::data = 100;

void test(){
	int *p = &A::data;
	cout << *p << endl;
	void(*pfunc)() = &A::dis;
	pfunc();
}
