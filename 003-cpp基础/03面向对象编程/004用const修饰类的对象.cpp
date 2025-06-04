#include<iostream>
using namespace std;

class Person{
public:
	Person(){
		this->mAge = 0;
		this->mID = 0;
	}
	void ChangePerson() const{
		//mAge = 100;这里是不能被修改的
		mID = 100;
	}
	void ShowPerson(){
        this->mAge = 1000;
		cout << "ID:" << this->mID << " Age:" << this->mAge << endl;
	}

public:
	int mAge;
	mutable int mID;
};

void test(){	
	const Person person;
	//1. 可访问数据成员
	cout << "Age:" << person.mAge << endl;
	//person.mAge = 300; //不可修改
	person.mID = 1001; //但是可以修改mutable修饰的成员变量
	//2. 只能访问const修饰的函数
	//person.ShowPerson();
	person.ChangePerson();
}
