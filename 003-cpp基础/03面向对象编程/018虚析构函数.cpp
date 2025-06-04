#include<iostream>
using namespace std;

//虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。

class People{
public:
	People(){
		cout << "构造函数 People!" << endl;
	}
	virtual void showName() = 0;
	virtual ~People(){
		cout << "析构函数 People!" << endl;
	}
};

//工人继承人
class Worker : public People{
public:
	Worker(){
		cout << "构造函数 Worker!" << endl;
		pName = new char[10];
	}
	virtual void showName(){
		cout << "打印子类的名字!" << endl;
	}
	~Worker(){
		cout << "析构函数 Worker!" << endl;
		if (pName != NULL){
			delete pName;
		}
	}
private:
	char* pName;
};

void test(){

	People* people = new Worker;
	people->~People();
}

int main(){
    test();
    return 0;
}
