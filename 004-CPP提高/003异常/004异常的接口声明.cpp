#include<iostream>
#include<string>
using namespace std;

/*
	为了加强程序的可读性，可以在函数声明中列出可能抛出异常的所有类型，例如：void func() throw(A,B,C);这个函数func能够且只能抛出类型A,B,C及其子类型的异常。
	如果在函数声明中没有包含异常接口声明，则此函数可以抛任何类型的异常，例如:void func()
	一个不抛任何类型异常的函数可声明为:void func() throw()
	如果一个函数抛出了它的异常接口声明所不允许抛出的异常,unexcepted函数会被调用，该函数默认行为调用terminate函数中断程序。
*/

//**********以下代码在linux上没问题，在windows10和MAC(报错)上测试失败****

//可抛出所有类型异常
void TestFunction01(){
	throw 10;
}

//只能抛出int char char*类型异常
void TestFunction02() //throw(int,char,char*)//MAC报错
{
	string exception = "error!";
	throw exception;
}

//不能抛出任何类型异常
void TestFunction03() throw(){
	throw 10;
}

int main(){

	try{
		//TestFunction01();
		//TestFunction02();
		//TestFunction03();
	}
	catch (...){
		cout << "捕获异常!" << endl;
	}
	
	system("pause");
	return EXIT_SUCCESS;
}

