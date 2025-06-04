#include<iostream>
using namespace std;
/*
	子类对象在创建时会首先调用父类的构造函数
	父类构造函数执行完毕后，才会调用子类的构造函数
	当父类构造函数有参数时，需要在子类初始化列表(参数列表)中显示调用父类构造函数
	析构函数调用顺序和构造函数相反
*/

class A{
public:
	A(){
		cout << "A类构造函数!" << endl;
	}
	~A(){
		cout << "A类析构函数!" << endl;
	}
};

class B : public A{
public:
	B(int a){
        this->a = a;
		cout << "B类构造函数!" << endl;
	}
	~B(){
		cout << "B类析构函数!" << endl;
	}
    int a;
};

class C : public B{
public:
	C(int a):B(a){//这里需要显示调用父类的有参构造函数
		cout << "C类构造函数!" << endl;
	}
	~C(){
		cout << "C类析构函数!" << endl;
	}
};

void test(){
	C c(12);
}
