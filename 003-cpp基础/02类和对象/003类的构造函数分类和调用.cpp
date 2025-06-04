#include <iostream>
using namespace std;


class Person{
public:
	//无参构造函数
	Person(){
		cout << "no param constructor!" << endl;
		mAge = 0;
	}
	//有参构造函数
	Person(int age){
		cout << "1 param constructor!" << endl;
		mAge = age;
	}
	//拷贝构造函数(复制构造函数) 使用另一个对象初始化本对象
	Person(const Person& person){
		cout << "copy constructor!" << endl;
		mAge = person.mAge;
	}
	//打印年龄
	void PrintPerson(){
		cout << "Age:" << mAge << endl;
	}
private:
	int mAge;
};
//1. 无参构造调用方式
void test01(){
	
	//调用无参构造函数
	Person person1; 
	person1.PrintPerson();

	//无参构造函数错误调用方式
	//Person person2();
	//person2.PrintPerson();
}
//2. 调用有参构造函数
void test02(){
	
	//第一种 括号法，最常用
	Person person01(100);
	person01.PrintPerson();

	//调用拷贝构造函数
	Person person02(person01);
	person02.PrintPerson();

	//第二种 匿名对象(显示调用构造函数)
	Person(200); //匿名对象，没有名字的对象

	Person person03 = Person(300);
	person03.PrintPerson();

	//注意: 使用匿名对象初始化判断调用哪一个构造函数，要看匿名对象的参数类型
	Person person06(Person(400)); //等价于 Person person06 = Person(400);
	person06.PrintPerson();

	//第三种 =号法 隐式转换
	Person person04 = 100; //Person person04 =  Person(100)
	person04.PrintPerson();

	//调用拷贝构造
	Person person05 = person04; //Person person05 =  Person(person04)
	person05.PrintPerson();
}

int main(int argc, char* args[]){

	test02();
	test01();

	return 0;
}