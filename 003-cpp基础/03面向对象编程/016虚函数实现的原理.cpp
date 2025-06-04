#include<iostream>
using namespace std;

/*
	为创建一个需要动态绑定的虚成员函数，可以简单在这个函数声明前面加上virtual关键字，定义时候不需要.
	如果一个函数在基类中被声明为virtual，那么在```*所有派生类*```中它都是virtual的.
	在派生类中virtual函数的重定义称为重写(overwrite).
	Virtual关键字只能修饰成员函数.
	构造函数不能为虚函数
原理:
编译器帮我们在有virtual声明函数的类中增加了vptr指针，指向一个虚函数表的结构
当子类继承基类，子类继承了基类的vptr指针，这个vptr指针是指向基类虚函数表，
当子类调用构造函数，使得子类的vptr指针指向了子类的虚函数表。
当子类函数被调用的时候，通过子类的vptr指针找到自己的函数
如果子类没有重写父类virtual方法，则vptr还是指向父类虚函数表
*/

class A{
public:
	virtual void func1(){}
	//virtual void func2(){}
};

//B类为空，那么大小应该是1字节，实际情况是这样吗？
class B : public A{};

void test(){
	cout << "A size:" << sizeof(A) << endl;
	cout << "B size:" << sizeof(B) << endl;
}

int main(){
    test();
    return 0;
}
