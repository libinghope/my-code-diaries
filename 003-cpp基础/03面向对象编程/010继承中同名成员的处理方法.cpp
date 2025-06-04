#include<iostream>
using namespace std;
/*
	当子类成员和父类成员同名时，子类依然从父类继承同名成员
	如果子类有成员和父类同名，子类访问其成员默认访问子类的成员(本作用域，就近原则)
	在子类通过作用域::进行同名成员区分(在派生类中使用基类的同名成员，显示使用类名限定符)
*/

class Base{
public:
	Base():mParam(0){}
	void Print(){ cout << mParam << endl; }
public:
	int mParam;
};

class Derived : public Base{
public:
	Derived():mParam(10){}
	void Print(){
		//在派生类中使用和基类的同名成员,显示使用类名限定符
		cout << Base::mParam << endl;
		cout << mParam << endl;
	}
	//返回基类重名成员
	int& getBaseParam(){ return  Base::mParam; }
public:
	int mParam;
};

int main(){

	Derived derived;
	//派生类和基类成员属性重名，子类访问成员默认是子类成员
	cout << derived.mParam << endl; //10
	derived.Print();
	//类外如何获得基类重名成员属性
	derived.getBaseParam() = 100;
	cout << "Base:mParam:" << derived.getBaseParam() << endl;

	return 0;
}
