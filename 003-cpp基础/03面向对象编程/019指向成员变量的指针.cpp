#include<iostream>
using namespace std;


class A{
public:
	A(int param){
		mParam = param;
	}
public:
	int mParam;
};

void test(){
	A a1(100);
	A* a2 = new A(200);
	int* p1 = &a1.mParam;
	int A::*p2 = &A::mParam;

	cout << "*p1:" << *p1 << endl;
	cout << "a1.*p2:" << a1.*p2 << endl;
	cout << "a2->*p2:" << a2->*p2 << endl;
}
