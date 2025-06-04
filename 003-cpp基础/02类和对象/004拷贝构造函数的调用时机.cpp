#include<iostream>
using namespace std;


class Person{
public:
	Person(){
		cout << "no param contructor!" << endl;
		mAge = 10;
	}
	Person(int age){
		cout << "param constructor!" << endl;
		mAge = age;
	}
	Person(const Person& person){
		cout << "copy constructor!" << endl;
		mAge = person.mAge;
	}
	~Person(){
		cout << "destructor!" << endl;
	}
public:
	int mAge;
};

//拷贝构造的3个时机
//1. 用旧对象初始化新对象
void test01(){

	Person p(10);
	Person p1(p);
	Person p2 = Person(p);
	Person p3 = p; // 相当于Person p2 = Person(p);
}

//2. 传递的参数是普通对象，函数参数也是普通对象，传递将会调用拷贝构造
void doBussiness(Person p){}

void test02(){
	Person p(10);
	doBussiness(p);
}

//3. 函数返回局部对象
Person MyBusiness(){
	Person p(10);
	cout << "局部p:" << (int*)&p << endl;
	return p;
}
void test03(){
	//vs release、qt下没有调用拷贝构造函数
	//vs debug下调用一次拷贝构造函数
	Person p = MyBusiness();
	cout << "局部p:" << (int*)&p << endl;
}
