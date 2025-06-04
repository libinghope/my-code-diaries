#include<iostream>

using namespace std;

class Person{
public:
	//类的静态成员属性,在执行main函数之前就已经初始化
	static int sNum;
private:
	static int sOther;
};
/*
静态成员变量必须在类中声明，在类外定义(初始化)。
静态数据成员不属于某个对象，在为对象分配空间中不包括静态成员所占空间。
静态数据成员可以通过类名或者对象名来引用。
*/
// 可以理解为某个类(及其对象)的全局变量
//类外初始化，初始化时不加static
int Person::sNum = 0;
int Person::sOther = 0;
/*
C++11标准针规定了局部静态变量初始化需要保证线程安全，具体说明如下：
If control enters the declaration concurrently while the variable is being initialized, 
the concurrent execution shall wait for completion of the initialization
*/
int main(){
	//1. 通过类名直接访问
	Person::sNum = 100;
	cout << "Person::sNum:" << Person::sNum << endl;

	//2. 通过对象访问
	Person p1, p2;
	p1.sNum = 200;

	cout << "p1.sNum:" << p1.sNum << endl;
	cout << "p2.sNum:" << p2.sNum << endl;

	//3. 静态成员也有访问权限，类外不能访问私有成员
	//cout << "Person::sOther:" << Person::sOther << endl;
	Person p3;
	//cout << "p3.sOther:" << p3.sOther << endl;

	system("pause");
	return 0;
}
