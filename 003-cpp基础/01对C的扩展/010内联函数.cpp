/*内联函数就像宏一样，是被直接展开使用
所以通常内联函数函数体不能太复杂
函数声明和函数定义必须在一起。通常内敛函数需要在函数定以前
加inline，但是并不一定，
类内部定义的函数(声明和定义)自动成为内敛函数。
内联只是给编译器的建议
*/
#include<iostream>
using namespace std;

class Person{
public:
    //以下两个函数自动变成内联函数
	Person(){ cout << "构造函数!" << endl; }
	void PrintPerson(){ cout << "输出Person!" << endl; }
};
