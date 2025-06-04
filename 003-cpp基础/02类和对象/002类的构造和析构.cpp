/*我们大家在购买一台电脑或者手机，或者其他的产品，这些产品
都有一个初始设置，也就是这些产品对被创建的时候会有一个基础
属性值。那么随着我们使用手机和电脑的时间越来越久，那么电脑
和手机会慢慢被我们手动创建很多文件数据，某一天我们不用手机
或电脑了，那么我们应该将电脑或手机中我们增加的数据删除掉，
保护自己的信息数据。
从这样的过程中，我们体会一下，所有的事物在起初的时候都应该
有个初始状态，当这个事物完成其使命时，应该及时清除外界作用
于上面的一些信息数据。
*/
//以上相当于我们设计一个类的构造(制造)和析构(销毁)过程
// 无论你是否喜欢，对象的初始化和清理工作是编译器强制我们
// 要做的事情，即使你不提供初始化操作和清理操作，编译器也
// 会给你增加默认的操作，只是这个默认初始化操作不会做任何
// 事，所以编写类就应该顺便提供初始化函数。
#include<iostream>
using namespace std;
#include<string.h>
#include<stdlib.h>
class Person{
public:
    //构造函数函数名和类名相同，没有返回值，不能有void，但可以有参数。
	Person(){
		cout << "构造函数调用!" << endl;
		pName = (char*)malloc(sizeof("John"));
		strcpy(pName, "John");
		mTall = 150;
		mMoney = 100;
	}

    //析构函数函数名是在类名前面加”~”组成,没有返回值，不能有void,不能有参数，不能重载。
    //析构函数主要用于对象销毁前系统自动调用，执行一些清理工作
	~Person(){
		cout << "析构函数调用!" << endl;
		if (pName != NULL){
			free(pName);
			pName = NULL;
		}
	}
public:
	char* pName;
	int mTall;
	int mMoney;
};

void test(){
	Person person;
	cout << person.pName << person.mTall << person.mMoney << endl;
}


int main(int arc, char* args[]){
	test();
	
	system("pause");
	return 0;
}









