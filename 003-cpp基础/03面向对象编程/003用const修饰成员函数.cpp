#include<iostream>
using namespace std;

//const修饰成员函数
class Person{
public:
	Person(){
		this->mAge = 0;
		this->mID = 0;
	}
	//在函数括号后面加上const,修饰成员变量不可修改,除了mutable变量
	void sonmeOperate() const{
		//this->mAge = 200; //mAge不可修改
		this->mID = 10;//用mutable修饰的变量可以被修改
	}
	void ShowPerson(){
		cout << "ID:" << mID << " mAge:" << mAge << endl;
	}
private:
	int mAge;
	mutable int mID;
};

int main(){

	Person person;
	person.sonmeOperate();
	person.ShowPerson();

	system("pause");
	return 0;
}
