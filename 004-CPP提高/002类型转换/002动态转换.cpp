#include<iostream>
using namespace std;

class Animal {
public:
	virtual void ShowName() = 0;
};
class Dog : public Animal{
	virtual void ShowName(){
		cout << "I am a dog!" << endl;
	}
};
class Other {
public:
	void PrintSomething(){
		cout << "我是其他类!" << endl;
	}
};

//普通类型转换
void test01(){

	//不支持基础数据类型
	int a = 10;
	//double a = dynamic_cast<double>(a);
}

//继承关系指针
void test02(){

	Animal* animal01 = NULL;
	Dog* dog01 = new Dog;

	//子类指针转换成父类指针 可以
	Animal* animal02 = dynamic_cast<Animal*>(dog01);
	animal02->ShowName();
	//父类指针转换成子类指针 不可以
	//Dog* dog02 = dynamic_cast<Dog*>(animal01);
}

//继承关系引用
void test03(){

	Dog dog_ref;
	Dog& dog01 = dog_ref;

	//子类引用转换成父类引用 可以
	Animal& animal02 = dynamic_cast<Animal&>(dog01);
	animal02.ShowName();
}

//无继承关系指针转换
void test04(){
	
	Animal* animal01 = NULL;
	Other* other = NULL;

	//不可以
	//Animal* animal02 = dynamic_cast<Animal*>(other);
}
