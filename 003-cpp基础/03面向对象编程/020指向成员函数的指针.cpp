#include<iostream>
using namespace std;

class A{
public:
	int func(int a,int b){
		return a + b;
	}
};

void test(){
	A a1;
	A* a2 = new A;

	//初始化成员函数指针
	int(A::*pFunc)(int, int) = &A::func;
	//指针解引用
	cout << "(a1.*pFunc)(10,20):" << (a1.*pFunc)(10, 20) << endl;
	cout << "(a2->*pFunc)(10,20):" << (a2->*pFunc)(10, 20) << endl;
}
