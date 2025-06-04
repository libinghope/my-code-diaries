#include<iostream>
using namespace std;

// 命名空间必须是全局的
namespace A{
	int a = 10;
}
namespace B{
	int a = 20;
}
void test1(){
	cout << "A::a : " << A::a << endl;
	cout << "B::a : " << B::a << endl;
}

namespace C{
	int a = 10;
	namespace D{
		int a = 20;
	}
}
void test2(){
	cout << "A::a : " << A::a << endl;
	cout << "A::B::a : " << C::D::a << endl;
}
//命名空间随时可以加入新的东西
namespace A{
	void func(){
		cout << "hello namespace!" << endl;
	}
}

namespace MySpace{
	void func1();
	void func2(int param);
}

void MySpace::func1(){
	cout << "MySpace::func1" << endl;
}
void MySpace::func2(int param){
	cout << "MySpace::func2 : " << param << endl;
}
namespace A{
	int paramA = 20;
	int paramB = 30;
	void funcA(){ cout << "hello funcA" << endl; }
	void funcB(){ cout << "hello funcB" << endl; }
}

void test01(){
	using namespace A;
	cout << paramA << endl;
	cout << paramB << endl;
	funcA();
	funcB();

	//不会产生二义性
	int paramA = 30;
	cout << paramA << endl;
}

namespace B{
	int paramA = 20;
	int paramB = 30;
	void funcA(){ cout << "hello funcA" << endl; }
	void funcB(){ cout << "hello funcB" << endl; }
}

void test02(){
	using namespace A;
	using namespace B;
	//二义性产生，不知道调用A还是B的paramA
	//cout << paramA << endl;
}


int main(){

    return 0;
}