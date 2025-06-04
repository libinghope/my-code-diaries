#include <iostream>
using namespace std;
/*
当类中有其他类的成员变量时候，
1、首先调用父类的构造函数
2、然后调用 成员变量的构造函数
3、最后调用子类的构造函数
4、析构的时候，顺序反过来
*/
class D
{
public:
    D()
    {
        cout << "D类构造函数!" << endl;
    }
    ~D()
    {
        cout << "D类析构函数!" << endl;
    }
};
class A
{
public:
    A()
    {
        cout << "A类构造函数!" << endl;
    }
    ~A()
    {
        cout << "A类析构函数!" << endl;
    }
};
class B : public A
{
public:
    B()
    {
        cout << "B类构造函数!" << endl;
    }
    ~B()
    {
        cout << "B类析构函数!" << endl;
    }
};
class C : public B
{
public:
    C()
    {
        cout << "C类构造函数!" << endl;
    }
    ~C()
    {
        cout << "C类析构函数!" << endl;
    }

public:
    D d;
};

void test()
{
    C c;
}

int main(){
    test();
    return 0;
}
