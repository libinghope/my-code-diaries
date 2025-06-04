#include <iostream>

using namespace std;
/*
一般赋值就是浅拷贝，当类中有指针指向堆内存空间时候，拷贝构造要为新对象申请空间，
避免多个对象内的指针指向同一块内存，其中一个对象析构后，早成其他对象出错，这就是深拷贝
*/
class Person{
public:
	Person(char* name,int age){
		//在构造函数中申请了堆内存空间，复制构造时候要注意，也为新对象申请堆空间
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName,name);
		mAge = age;
	}
	//增加拷贝构造函数
	Person(const Person& person){
		pName = (char*)malloc(strlen(person.pName) + 1);
		strcpy(pName, person.pName);
		mAge = person.mAge;
	}
	~Person(){
		if (pName != NULL){
			free(pName);
		}
	}
private:
	char* pName;
	int mAge;
};

void test(){
	Person p1("Edward",30);
	//用对象p1初始化对象p2,
	Person p2 = p1;
}
