#include <iostream>

using namespace std;

/*
c++提供了关键字explicit，禁止通过构造函数进行的隐式转换。
声明为explicit的构造函数不能在隐式转换中使用。使用时需要
注意一下两点:
1、explicit用于修饰构造函数，防止隐式转化。
2、构造函数必须是单参数(或者其余参数都有默认值)
*/

class MyString{
public:
	explicit MyString(int n){
		cout << "MyString(int n)!" << endl;
	}
	MyString(const char* str){
		cout << "MyString(const char* str)" << endl;
	}
};

int main(){

	//给字符串赋值？还是初始化？
	//MyString str1 = 1; 
	MyString str2(10);

	//寓意非常明确，给字符串赋值
	MyString str3 = "abcd";
	MyString str4("abcd");

	return 0;
}
