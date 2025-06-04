#include <iostream>

using namespace std;

/*
在c++中，一个类初始化时候，内部的成员变量也是要初始化的。但是成员变量有可
能是私有的，无法在类外访问。对于成员调用构造函数的问题，C++提供了专门的语
法，即构造函数初始化列表。当调用构造函数时候，首先按照对象成员在类中的定义
顺序(和参数列表的顺序无关)，依次调用他们的构造函数，最后调用自身的构造。
当析构的时候，析构顺序与构造顺序相反。
*/

class Car
{
public:
    Car()
    {
        cout << "调用Car的无参构造函数。。。" << endl;
    }
    Car(string name){
		cout << "Car 带参数name的构造函数!" << endl;
		mName = name;
	}
	~Car(){
		cout << "Car 析构函数!" << endl;
	}
public:
	string mName;

};

//拖拉机
class Tractor{
public:
	Tractor(){
		cout << "Tractor 无参构造函数!" << endl;
		mName = "爬土坡专用拖拉机";
	}
	Tractor(string name){
		cout << "Tractor 带参数name构造函数!" << endl;
		mName = name;
	}
	~Tractor(){
		cout << "Tractor 析构函数!" << endl;
	}
public:
	string mName;
};

//人类
class Person{
public:
#if 1
	//类mCar不存在合适的构造函数
	Person(string name){
		mName = name;
	}
#else
	//初始化列表可以指定调用构造函数
	Person(string carName, string tracName, string name) : mTractor(tracName), mCar(carName), mName(name){
		cout << "Person 构造函数!" << endl;
	}
#endif
	
	void GoWorkByCar(){
		cout << mName << "开着" << mCar.mName << "去上班!" << endl;
	}
	void GoWorkByTractor(){
		cout << mName << "开着" << mTractor.mName << "去上班!" << endl;
	}
	~Person(){
		cout << "Person 析构函数!" << endl;
	}
private:
	string mName;
	Car mCar;
	Tractor mTractor;
};

int main(){
	//Person person("宝马", "东风拖拉机", "赵四");
	Person person("刘能");
	person.GoWorkByCar();
	person.GoWorkByTractor();

    return 0;
}
