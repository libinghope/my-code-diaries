#include<iostream>
using namespace std;

//非纯虚析构函数
class A{
public:
	virtual ~A();
};

A::~A(){}

//纯析构函数
class B{
public:
	virtual ~B() = 0;
};

B::~B(){}//要提供空析构函数

void test(){
	A a; //A类不是抽象类，可以实例化对象
	//B b; //B类是抽象类，不可以实例化对象
}
