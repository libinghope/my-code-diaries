#include<iostream>
using namespace std;
/*
类模板的声明和实现放到一个文件中，我们把这个文件命名为.hpp(这个是个约定的规则，并不是标准，必须这么写).
原因：
	类模板需要二次编译，在出现模板的地方编译一次，在调用模板的地方再次编译。
	C++编译规则为独立编译。
*/

template<typename T>
class MyClass{
//也就是说模板类的所有功能要在一个单独的文件中完成，文件后缀名为.hpp
};