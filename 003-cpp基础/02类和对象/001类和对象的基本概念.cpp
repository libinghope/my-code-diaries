#include<iostream>
using namespace std;
//封装两层含义
//1. 属性和行为合成一个整体
//2. 访问控制，现实事物本身有些属性和行为是不对外开放
class Person{
//人具有的行为(函数) 
public:
	
	void Dese(){ cout << "我有钱，年轻，个子又高，就爱嘚瑟!" << endl;}
//人的属性(变量)
public:
	int mTall; //多高，可以让外人知道
protected:
	int mMoney; // 有多少钱,只能儿子孙子知道
private:
	int mAge; //年龄，不想让外人知道
};

int main(){

	Person p;
	p.mTall = 220;
	//p.mMoney 保护成员外部无法访问
	//p.mAge 私有成员外部无法访问
	p.Dese();

	return EXIT_SUCCESS;
}

