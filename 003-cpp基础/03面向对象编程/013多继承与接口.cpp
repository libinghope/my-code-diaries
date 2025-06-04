#include<iostream>
using namespace std;
/*
多继承很多时候会让人费解，还是觉得java中的处理方式比较好
java中不允许多继承，接口(interface)除外
C++的多继承感觉是弊大于利,更有甚者会有菱形继承的情况出现，严重干扰理解代码的思路
虚继承更是多此一举，毫无存在的必要(也许是个人偏见)
个人还是倾向于像java的接口一样使用多继承
*/


class Base1{
public:
	void func1(){ cout << "Base1::func1" << endl; }
};
class Base2{
public:
	void func1(){ cout << "Base2::func1" << endl; }
	void func2(){ cout << "Base2::func2" << endl; }
};
//派生类继承Base1、Base2
class Derived : public Base1, public Base2{};
int main(){

	Derived derived;
	//func1是从Base1继承来的还是从Base2继承来的？
	//derived.func1(); 
	derived.func2();

	//解决歧义:显示指定调用那个基类的func1
	derived.Base1::func1(); 
	derived.Base2::func1();

	return 0;
}
