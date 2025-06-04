#include<iostream>
using namespace std;

/*c++最重要的特征是代码重用，通过继承机制可以利用已有的数据类型来定义新的数据类型，
新的类不仅拥有旧类的成员，还拥有新定义的成员。一个B类继承于A类，或称从类A派生类B。
这样的话，类A成为基类（父类）， 类B成为派生类（子类）。
*/

class A
{
public:
    int mA;

protected:
    int mB;

private:
    int mC;
};

/* 以下代码即是继承基本方法
派生类继承基类，派生类拥有基类中 ``*全部*`` 成员变量和成员方法（``*除了*``构造和析构之外的成员方法），
但是在派生类中，继承的成员并不一定能直接访问，不同的继承方式会导致不同的访问权限。
*/
//1. 公有(public)继承
class B : public A{
public:
	void PrintB(){
		cout << mA << endl; //可访问基类public属性
		cout << mB << endl; //可访问基类protected属性
		//cout << mC << endl; //不可访问基类private属性
	}
};
class SubB : public B{
	void PrintSubB(){
		cout << mA << endl; //可访问基类public属性
		cout << mB << endl; //可访问基类protected属性
		//cout << mC << endl; //不可访问基类private属性
	}
};
void test01(){

	B b;
	cout << b.mA << endl; //可访问基类public属性
	//cout << b.mB << endl; //不可访问基类protected属性
	//cout << b.mC << endl; //不可访问基类private属性
}

//2. 私有(private)继承,继承的共有成员变成私有
class C : private A{
public:
	void PrintC(){
		cout << mA << endl; //可访问基类public属性
		cout << mB << endl; //可访问基类protected属性
		//cout << mC << endl; //不可访问基类private属性
	}
};
class SubC : public C{
	void PrintSubC(){
		//cout << mA << endl; //不可访问基类public属性
		//cout << mB << endl; //不可访问基类protected属性
		//cout << mC << endl; //不可访问基类private属性
	}
};
void test02(){
	C c;
	//cout << c.mA << endl; //不可访问基类public属性
	//cout << c.mB << endl; //不可访问基类protected属性
	//cout << c.mC << endl; //不可访问基类private属性
}
//3. 保护(protected)继承
class D : protected A{
public:
	void PrintD(){
		cout << mA << endl; //可访问基类public属性
		cout << mB << endl; //可访问基类protected属性
		//cout << mC << endl; //不可访问基类private属性
	}
};
class SubD : public D{
	void PrintD(){
		cout << mA << endl; //可访问基类public属性
		cout << mB << endl; //可访问基类protected属性
		//cout << mC << endl; //不可访问基类private属性
	}
};
void test03(){
	D d;
	//cout << d.mA << endl; //不可访问基类public属性
	//cout << d.mB << endl; //不可访问基类protected属性
	//cout << d.mC << endl; //不可访问基类private属性
}
