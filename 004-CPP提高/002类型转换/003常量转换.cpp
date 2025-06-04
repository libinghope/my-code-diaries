#include<iostream>
using namespace std;

//常量指针转换成非常量指针
void test01(){
	
	const int* p = nullptr;
	int* np = const_cast<int*>(p);

	int* pp = nullptr;
	const int* npp = const_cast<const int*>(pp);

	const int a = 10;  //不能对非指针或非引用进行转换
	//int b = const_cast<int>(a); 
}

//常量引用转换成非常量引用
void test02(){

    int num = 10;
	int & refNum = num;

	const int& refNum2 = const_cast<const int&>(refNum);
	
}
