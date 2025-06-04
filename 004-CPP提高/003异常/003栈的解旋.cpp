#include<iostream>
#include<string>
using namespace std;

/*
异常被抛出后，从进入try块起，到异常被抛掷前，
这期间在栈上构造的所有对象，
都会被自动析构。析构的顺序与构造的顺序相反，
这一过程称为栈的解旋(unwinding).
*/
class Person{
public:
	Person(string name){
		mName = name;
		cout << mName << "对象被创建!" << endl;
	}
	~Person(){
		cout << mName << "对象被析构!" << endl;
	}
public:
	string mName;
};

void TestFunction(){
	
	Person p1("aaa");
	Person p2("bbb");
	Person p3("ccc");

	//抛出异常
	throw 10;
}

int main(){

	try{
		TestFunction();
	}
	catch (...){
		cout << "异常被捕获!" << endl;
	}
	return 0;
}
