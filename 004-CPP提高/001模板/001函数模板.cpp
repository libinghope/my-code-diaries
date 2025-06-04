#include<iostream>
using namespace std;

//如下是交换int数据的函数
void SwapInt(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

//交换char数据的函数
void SwapChar(char& a,char& b){
	char temp = a;
	a = b;
	b = temp;
}
//问题：如果我要交换double类型数据，那么还需要些一个double类型数据交换的函数
//繁琐，写的函数越多，当交换逻辑发生变化的时候，所有的函数都需要修改，无形当中增加了代码的维护难度

//如果能把类型作为参数传递进来就好了，传递int就是Int类型交换，传递char就是char类型交换
//我们有一种技术，可以实现类型的参数化---函数模板


//class 和 typename都是一样的，用哪个都可以
template<class T>
void MySwap(T& a,T& b){
	T temp = a;
	a = b;
	b = temp;
}

void test01(){
	
	int a = 10;
	int b = 20;
	cout << "a:" << a << " b:" << b << endl;
	//1. 这里有个需要注意点，函数模板可以自动推导参数的类型
	MySwap(a,b);
	cout << "a:" << a << " b:" << b << endl;

	char c1 = 'a';
	char c2 = 'b';
	cout << "c1:" << c1 << " c2:" << c2 << endl;
	//2. 函数模板可以自动类型推导，那么也可以显式指定类型
	MySwap<char>(c1, c2);
	cout << "c1:" << c1 << " c2:" << c2 << endl;
}

//其原理可以认为是编译器帮我们复制了好几分模板代码
//实际用到几种类型就复制几份代码(就像函数重载)，一种类型就替换出一个方法，包括后面的类模板
//另外模板函数不允许自动类型转换，模板函数也可以实现重载
int main(){
    test01();
    return 0;
}
