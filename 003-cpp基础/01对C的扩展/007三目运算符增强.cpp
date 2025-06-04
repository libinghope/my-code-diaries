#include <iostream>
using namespace std;

int main()
{
    // 	c语言三目运算表达式返回值为数据值，为右值，不能赋值。
    int a = 10;
    int b = 20;
    printf("ret:%d\n", a > b ? a : b);
    //思考一个问题，(a > b ? a : b) 三目运算表达式返回的是什么？

    //(a > b ? a : b) = 100;
    //返回的是右值

    // 	c++语言三目运算表达式返回值为变量本身(引用)，为左值，可以赋值。
    int a = 10;
    int b = 20;
    printf("ret:%d\n", a > b ? a : b);
    //思考一个问题，(a > b ? a : b) 三目运算表达式返回的是什么？

    cout << "b:" << b << endl;
    //返回的是左值，变量的引用
    (a > b ? a : b) = 100; //返回的是左值，变量的引用
    cout << "b:" << b << endl;

    return 0;
}