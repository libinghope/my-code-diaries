#include<iostream>
using namespace std;
// 实现函数重载的条件：
// 	同一个作用域
// 	参数个数不同
// 	参数类型不同
// 	参数顺序不同

//1. 函数重载条件
namespace A{
	void MyFunc(){ cout << "无参数!" << endl; }
	void MyFunc(int a){ cout << "a: " << a << endl; }
	void MyFunc(string b){ cout << "b: " << b << endl; }
	void MyFunc(int a, string b){ cout << "a: " << a << " b:" << b << endl;}
    void MyFunc(string b, int a){cout << "a: " << a << " b:" << b << endl;}
}
//2.返回值不作为函数重载依据
namespace B{
	void MyFunc(string b, int a){}
	//int MyFunc(string b, int a){} //无法重载仅按返回值区分的函数
}

// 注意: 函数重载和默认参数一起使用，需要额外注意二义性问题的产生。
void MyFunc(string b){
	cout << "b: " << b << endl;
}
//函数重载碰上默认参数
void MyFunc(string b, int a = 10){
	cout << "a: " << a << " b:" << b << endl;
}
int main(){
	//MyFunc("hello"); //这时，两个函数都能匹配调用，产生二义性
	return 0;
}
