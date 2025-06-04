#include <iostream>
using namespace std;

class Person{
public:
	Person(){
		cout << "无参构造函数!" << endl;
		pName = (char*)malloc(strlen("undefined") + 1);
		strcpy(pName, "undefined");
		mAge = 0;
	}
	Person(char* name, int age){
		cout << "有参构造函数!" << endl;
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}
	void ShowPerson(){
		cout << "Name:" << pName << " Age:" << mAge << endl;
	}
	~Person(){
		cout << "析构函数!" << endl;
		if (pName != NULL){
			//delete pName;
            free(pName);
			pName = NULL;
		}
	}
public:
	char* pName;
	int mAge;
};
/*
New操作符能确定在调用构造函数初始化之前内存分配是成功的，所有不用显式确定调用是否成功。

new表达式的反面是delete表达式。delete表达式先调用析构函数，然后释放内存。
正如new表达式返回一个指向对象的指针一样，delete需要一个对象的地址。
delete只适用于由new创建的对象。

如果使用一个由malloc或者calloc或者realloc创建的对象使用delete,这个行为是未定义的。
因为大多数new和delete的实现机制都使用了malloc和free,所以很可能没有调用析构函数就释放了内存。
如果正在删除的对象的指针是NULL,将不发生任何事，因此建议在删除指针后，立即把指针赋值为NULL，
以免对它删除两次，对一些对象删除两次可能会产生某些问题

*/
void test(){
	Person* person1 = new Person;
	Person* person2 = new Person("John",33);

	person1->ShowPerson();
	person2->ShowPerson();

	delete person1;
	delete person2;
}
